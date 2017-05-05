#pragma once

#include <Types.h>

#ifdef __cplusplus
extern "C" {
#endif

int Region_getID(Region* self);
int Region_getRegionGroupID(Region* self);
Position Region_getCenter(Region* self);
bool Region_isHigherGround(Region* self);
int Region_getDefensePriority(Region* self);
bool Region_isAccessible(Region* self);
//TODO const Regionset &getNeighbors();
int Region_getBoundsLeft(Region* self);
int Region_getBoundsTop(Region* self);
int Region_getBoundsRight(Region* self);
int Region_getBoundsBottom(Region* self);
Region* Region_getClosestAccessibleRegion(Region* self);
Region* Region_getClosestInaccessibleRegion(Region* self);
int Region_getDistance(Region* self, Region* other);
//TODO Unitset getUnits(const UnitFilter &pred = nullptr) const;

#ifdef __cplusplus
}
#endif
