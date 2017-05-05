#include <String.h>

#include <stdlib.h>
#include <string.h>

struct String_ {
    char* data;
    size_t length;
};

String* String_new(const char* data, size_t len) {
    String* self = new String();
    self->length = len;

    self->data = new char[len + 1 /* terminating \0 */];
    memmove(self->data, data, len);
    self->data[len] = '\0';

    return self;
}

char* String_data(String* self) {
    return self->data;
}

size_t String_len(String* self) {
    return self->length;
}

void String_release(String* self) {
    delete[] self->data;
    delete self;
}
