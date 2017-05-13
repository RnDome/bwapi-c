#pragma once

#include <Types.h>
#include <BWAPI/CoordinateType.h>

inline BWAPI::CoordinateType::Enum coordinatetype_to_bw(CoordinateType type) {
    return static_cast<BWAPI::CoordinateType::Enum>(type.id);
}

inline CoordinateType coordinatetype_from_bw(BWAPI::CoordinateType::Enum type) {
    CoordinateType self;
    self.id = static_cast<int>(type);
    return self;
}
