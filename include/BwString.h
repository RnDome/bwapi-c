#pragma once

#include <Types.h>

#ifdef __cplusplus
extern "C" {
#endif

BwString* BwString_new(const char* data, size_t len);
char* BwString_data(BwString* self);
size_t BwString_len(BwString* self);
void BwString_release(BwString* self);

#ifdef __cplusplus
} // extern "C"
#endif
