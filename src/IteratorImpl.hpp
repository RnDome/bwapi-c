#pragma once

#include <utility>
#include <Iterator.h>
#include "Cast.hpp"

enum IteratorType {
    itUnknown = 0,
    itUnit,
    itPlayer,
    itForce,
    itBullet,
    itRegion,
    itPosition,
    itEvent,
    itUnitType,
    itTilePosition
};

class IteratorBase {
public:
    virtual ~IteratorBase();

    // Can be used for runtime checks
    virtual IteratorType id() const = 0;

    virtual bool valid() const = 0;
    virtual void* get() const = 0;
    virtual void next() = 0;
};

template<class Container, IteratorType type>
class OwningIterator : public IteratorBase {
public:
    typedef typename Container::const_iterator Iter;

    OwningIterator(Container c)
        : container(std::move(c)), iter(container.begin())
    {
        static_assert(type != itUnknown, "Iterator type must be valid");
    }

    virtual IteratorType id() const override { return type; }
    virtual bool valid() const override { return iter != container.end(); }
    virtual void* get() const override { return *iter; }

    virtual void next() override {
        if (iter != container.end())
            ++iter;
    }

private:
    Container container;
    Iter iter;
};

template<class Container, IteratorType type>
class BorrowingIterator : public IteratorBase {
public:
    typedef typename Container::const_iterator Iter;

    BorrowingIterator(const Container& c)
        : container(c), iter(container.begin())
    {
        static_assert(type != itUnknown, "Iterator type must be valid");
    }

    virtual IteratorType id() const override { return type; }
    virtual bool valid() const override { return iter != container.end(); }
    virtual void* get() const override { return *iter; }

    virtual void next() override {
        if (iter != container.end())
            ++iter;
    }

private:
    const Container& container;
    Iter iter;
};

template<class Container, class ValueType, IteratorType type>
class ValueOwningIterator : public IteratorBase {
public:
    typedef typename Container::const_iterator        Iter;
    typedef typename CastFwd<ValueType>::Type::TxType ToValueType;

    ValueOwningIterator(Container c)
        : container(std::move(c)), iter(container.begin())
    {
        static_assert(type != itUnknown, "Iterator type must be valid");
        update_current();
    }

    virtual IteratorType id() const override { return type; }
    virtual bool valid() const override { return iter != container.end(); }
    virtual void* get() const override { return const_cast<ToValueType*>(&current); }

    virtual void next() override {
        if (valid()) {
            ++iter;
            update_current();
        }
    }

private:

    void update_current() {
        if (valid()) {
            current = cast_from_bw(*iter);
        }
    }

    Container container;
    Iter iter;
    ToValueType current;
};

template<class Container, class ValueType, IteratorType type>
class ValueBorrowingIterator : public IteratorBase {
public:
    typedef typename Container::const_iterator        Iter;
    typedef typename CastFwd<ValueType>::Type::TxType ToValueType;

    ValueBorrowingIterator(const Container& c)
        : container(c), iter(container.begin())
    {
        static_assert(type != itUnknown, "Iterator type must be valid");
        update_current();
    }

    virtual IteratorType id() const override { return type; }
    virtual bool valid() const override { return iter != container.end(); }
    virtual void* get() const override { return const_cast<ToValueType*>(&current); }

    virtual void next() override {
        if (valid()) {
            ++iter;
            update_current();
        }
    }

private:

    void update_current() {
        if (valid()) {
            current = cast_from_bw(*iter);
        }
    }

    const Container& container;
    Iter iter;
    ToValueType current;
};

template<class T> struct GetIterType {
    enum { value = itUnknown };
};

template<> struct GetIterType<UnitIterator> {
    enum { value = itUnit };
};

template<> struct GetIterType<PlayerIterator> {
    enum { value = itPlayer };
};

template<> struct GetIterType<ForceIterator> {
    enum { value = itForce };
};

template<> struct GetIterType<BulletIterator> {
    enum { value = itBullet };
};

template<> struct GetIterType<RegionIterator> {
    enum { value = itRegion };
};

template<> struct GetIterType<PositionIterator> {
    enum { value = itPosition };
};

template<> struct GetIterType<EventIterator> {
    enum { value = itEvent };
};

template<> struct GetIterType<UnitTypeIterator> {
    enum { value = itUnitType };
};

template<> struct GetIterType<TilePositionIterator> {
    enum { value = itTilePosition };
};


template<class Out, class Container>
Out* into_iter(Container container) {
    const auto type = static_cast<IteratorType>(GetIterType<Out>::value);
    static_assert(type != itUnknown, "Out must be registered, see GetIterType<T>");

    IteratorBase* const iter = new OwningIterator<Container, type>(std::move(container));
    return reinterpret_cast<Out*>(iter);
}

template<class Out, class Container>
Out* as_iter(const Container& container) {
    const auto type = static_cast<IteratorType>(GetIterType<Out>::value);
    static_assert(type != itUnknown, "Out must be registered, see GetIterType<T>");

    IteratorBase* const iter = new BorrowingIterator<Container, type>(container);
    return reinterpret_cast<Out*>(iter);
}

template<class Out, class Container>
Out* into_value_iter(Container container) {
    const auto type = static_cast<IteratorType>(GetIterType<Out>::value);
    static_assert(type != itUnknown, "Out must be registered, see GetIterType<T>");
    typedef typename Container::value_type ValueType;

    IteratorBase* const iter = new ValueOwningIterator<Container, ValueType, type>(std::move(container));
    return reinterpret_cast<Out*>(iter);
}

template<class Out, class Container>
Out* as_value_iter(const Container& container) {
    const auto type = static_cast<IteratorType>(GetIterType<Out>::value);
    static_assert(type != itUnknown, "Out must be registered, see GetIterType<T>");
    typedef typename Container::value_type ValueType;

    IteratorBase* const iter = new ValueBorrowingIterator<Container, ValueType, type>(container);
    return reinterpret_cast<Out*>(iter);
}
