#pragma once

#include <Types.h>

#ifdef __cplusplus
extern "C" {
#endif

String* String_newFrom(const char* data, int len);
char* String_data(String* self);
int String_len(String* self);
void String_release(String* self);

#ifdef __cplusplus
} // extern "C"
#endif
