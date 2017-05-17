#pragma once

#include <utility>
#include <Iterator.h>

// FIXME Probbaly there is something similar in the BWAPI
enum IteratorType {
    itUnknown = 0,
    itUnit,
    itPlayer,
    itForce,
    itBullet,
    itRegion,
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

    OwningIterator(Container container)
        : container_(std::move(container)), iter(container_.begin())
    {
        static_assert(type != itUnknown, "Iterator type must be valid");
    }

    virtual IteratorType id() const override { return type; }
    virtual bool valid() const override { return iter != container_.end(); }
    virtual void* get() const override { return *iter; }

    virtual void next() override {
        if (iter != container_.end())
            ++iter;
    }

private:
    Container container_;
    Iter iter;
};

template<class Container, IteratorType type>
class BorrowingIterator : public IteratorBase {
public:
    typedef typename Container::const_iterator Iter;

    BorrowingIterator(const Container& container)
        : container_(container), iter(container_.begin())
    {
        static_assert(type != itUnknown, "Iterator type must be valid");
    }

    virtual IteratorType id() const override { return type; }
    virtual bool valid() const override { return iter != container_.end(); }
    virtual void* get() const override { return *iter; }

    virtual void next() override {
        if (iter != container_.end())
            ++iter;
    }

private:
    const Container& container_;
    Iter iter;
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
