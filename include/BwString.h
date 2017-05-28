#pragma once

#include <Types.h>

#ifdef __cplusplus
extern "C" {
#endif

BwString* BwString_new(const char* data, int len);
const char* BwString_data(const BwString* self);
int BwString_len(const BwString* self);
void BwString_release(BwString* self);

#ifdef __cplusplus
} // extern "C"
#endif
