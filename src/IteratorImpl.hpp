#pragma once

#include <Iterator.h>

// FIXME Probbaly there is something similar in the BWAPI
enum IteratorType {
    itUnknown = 0,
    itUnit,
};

class IteratorBase {
public:
    virtual ~IteratorBase();

    // Can be used for runtime checks
    virtual IteratorType id() const = 0;

    virtual bool valid() const = 0;
    virtual const void* get() const = 0;
    virtual void next() = 0;
};

template<class Container, IteratorType type>
class OwningIterator : public IteratorBase {
public:
    typedef typename Container::const_iterator Iter;

    OwningIterator(Container container)
        : container(container), iter(container.begin())
    {
        static_assert(type != itUnknown, "Iterator type must be valid");
    }

    virtual IteratorType id() const override { return type; }
    virtual bool valid() const override { return iter != container.end(); }
    virtual const void* get() const override { return &*iter; }

    virtual void next() override {
        if (iter != container.end())
            ++iter;
    }

private:
    Container container;
    Iter iter;
};

template<class T> struct GetIterType {
    enum { value = itUnknown };
};

template<> struct GetIterType<UnitIterator> {
    enum { value = itUnit };
};

template<class Out, class Container>
Out* into_iter(Container container) {
    const auto type = static_cast<IteratorType>(GetIterType<Out>::value);
    static_assert(type != itUnknown, "Out must be registered, see GetIterType<T>");

    IteratorBase* const iter = new OwningIterator<Container, type>(container);
    return reinterpret_cast<Out*>(iter);
}
