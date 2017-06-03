#include <Region.h>
#include <BWAPI/Region.h>
#include <BWAPI/Regionset.h>
#include <BWAPI/Unitset.h>

#include "Position.hpp"
#include "IteratorImpl.hpp"

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

RegionIterator* Region_getNeighbors(Region* self) {
    const auto regions = reinterpret_cast<BWAPI::Region>(self)->getNeighbors();
    return into_iter<RegionIterator>(regions);
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

UnitIterator* Region_getUnits(Region* self, UnaryUnitFilter pred) {
    auto pred_filter = reinterpret_cast<bool (*)(BWAPI::Unit)>(pred);
    auto&& units = reinterpret_cast<BWAPI::Region>(self)->getUnits(pred_filter);
    return into_iter<UnitIterator>(std::move(units));
}
