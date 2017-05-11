#pragma once

#include <Types.h>
#include <BWAPI/Race.h>

inline BWAPI::Race race_to_bw(Race race) {
    return BWAPI::Race(race.id);
}

inline Race race_from_bw(BWAPI::Race type) {
    Race self;
    self.id = type.getID();
    return self;
}
