#include <BwString.h>

#include <stdlib.h>
#include <string.h>

struct BwString_ {
    char* data;
    size_t length;
};

BwString* BwString_new(const char* data, size_t len) {
    BwString* self = new BwString();
    self->length = len;

    self->data = new char[len + 1 /* terminating \0 */];
    memmove(self->data, data, len);
    self->data[len] = '\0';

    return self;
}

char* BwString_data(BwString* self) {
    return self->data;
}

size_t BwString_len(BwString* self) {
    return self->length;
}

void BwString_release(BwString* self) {
    delete[] self->data;
    delete self;
}
