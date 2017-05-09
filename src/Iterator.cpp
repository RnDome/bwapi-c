#include "IteratorImpl.hpp"
#include <BWAPI/Unitset.h>

#include <assert.h>

IteratorBase::~IteratorBase() {
}

bool Iterator_valid(const Iterator* self) {
    assert(self);
    return reinterpret_cast<const IteratorBase*>(self)->valid();
}

const void* Iterator_get(const Iterator* self) {
    assert(self);
    return reinterpret_cast<const IteratorBase*>(self)->get();
}

void Iterator_next(Iterator* self) {
    assert(self);
    reinterpret_cast<IteratorBase*>(self)->next();
}

void Iterator_release(Iterator* self) {
    assert(self);
    delete reinterpret_cast<IteratorBase*>(self);
}
