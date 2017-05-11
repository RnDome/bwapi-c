#pragma once

#include <Types.h>
#include <BWAPI/TechType.h>

inline BWAPI::TechType techtype_to_bw(TechType type) {
    return BWAPI::TechType(type.id);
}

inline TechType techtype_from_bw(BWAPI::TechType type) {
    TechType self;
    self.id = type.getID();
    return self;
}
