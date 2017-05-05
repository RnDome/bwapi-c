#pragma once

#include <Types.h>

#ifdef __cplusplus
extern "C" {
#endif

String* String_newFrom(const char* data, size_t len);
char* String_data(String* self);
size_t String_len(String* self);
void String_release(String* self);

#ifdef __cplusplus
} // extern "C"
#endif
