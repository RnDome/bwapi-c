#include <Region.h>
#include <BWAPI/Region.h>

#include "Position.hpp"

int Region_getID(Region* self) {
    return reinterpret_cast<BWAPI::Region>(self)->getID();
}

int Region_getRegionGroupID(Region* self) {
    return reinterpret_cast<BWAPI::Region>(self)->getRegionGroupID();
}

Position Region_getCenter(Region* self) {
    return position_from_bw( reinterpret_cast<BWAPI::Region>(self)->getCenter() );
}

bool Region_isHigherGround(Region* self) {
    return reinterpret_cast<BWAPI::Region>(self)->isHigherGround();
}

int Region_getDefensePriority(Region* self) {
    return reinterpret_cast<BWAPI::Region>(self)->getDefensePriority();
}

bool Region_isAccessible(Region* self) {
    return reinterpret_cast<BWAPI::Region>(self)->isAccessible();
}

int Region_getBoundsLeft(Region* self) {
    return reinterpret_cast<BWAPI::Region>(self)->getBoundsLeft();
}

int Region_getBoundsTop(Region* self) {
    return reinterpret_cast<BWAPI::Region>(self)->getBoundsTop();
}

int Region_getBoundsRight(Region* self) {
    return reinterpret_cast<BWAPI::Region>(self)->getBoundsRight();
}

int Region_getBoundsBottom(Region* self) {
    return reinterpret_cast<BWAPI::Region>(self)->getBoundsBottom();
}

Region* Region_getClosestAccessibleRegion(Region* self) {
    return reinterpret_cast<Region*>( reinterpret_cast<BWAPI::Region>(self)->getClosestAccessibleRegion() );
}

Region* Region_getClosestInaccessibleRegion(Region* self) {
    return reinterpret_cast<Region*>( reinterpret_cast<BWAPI::Region>(self)->getClosestInaccessibleRegion() );
}

int Region_getDistance(Region* self, Region* other) {
    return reinterpret_cast<BWAPI::Region>(self)->getDistance(reinterpret_cast<BWAPI::Region>(other));
}
