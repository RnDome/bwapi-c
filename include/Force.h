#pragma once

#include <Types.h>

#ifdef __cplusplus
extern "C" {
#endif

int Force_getID(Force* self);
BwString* Force_getName(Force* self);
PlayerIterator* Force_getPlayers(Force* self);

#ifdef __cplusplus
} // extern "C"
#endif
