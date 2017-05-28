#include <BwString.h>

#include <string>
#include <assert.h>

struct BwString_ {
    std::string data;
};

BwString* BwString_new(const char* data, int len) {
    assert(data);

    BwString* const self = new BwString();
    self->data.assign(data, len);
    return self;
}

const char* BwString_data(const BwString* self) {
    assert(self);
    return self->data.c_str();
}

int BwString_len(const BwString* self) {
    assert(self);
    return self->data.length();
}

void BwString_release(BwString* self) {
    assert(self);
    delete self;
}
