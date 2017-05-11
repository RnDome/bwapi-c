#pragma once

#include <Types.h>
#include <BWAPI/UnitType.h>

inline BWAPI::UnitType unittype_to_bw(UnitType type) {
    return BWAPI::UnitType(type.id);
}

inline UnitType unittype_from_bw(BWAPI::UnitType type) {
    UnitType self;
    self.id = type.getID();
    return self;
}
