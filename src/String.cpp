#include <String.h>

#include <stdlib.h>
#include <string.h>

struct String_ {
    char* data;
    int length;
};

String* String_newFrom(const char* data, int len) {
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

int String_len(String* self) {
    return self->length;
}

void String_release(String* self) {
    delete[] self->data;
    delete self;
}
