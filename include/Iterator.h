#pragma once

#include <Types.h>

#ifdef __cplusplus
extern "C" {
#endif

bool Iterator_valid(const Iterator* self);
void* Iterator_get(const Iterator* self);
void Iterator_next(Iterator* self);
void Iterator_release(Iterator* self);

#ifdef __cplusplus
} // extern "C"
#endif

