#pragma once

#include <Types.h>

#ifdef __cplusplus
extern "C" {
#endif

int Force_getID(Force* self);
BwString* Force_getName(Force* self);
// TODO virtual Playerset getPlayers() const = 0;

#ifdef __cplusplus
} // extern "C"
#endif
