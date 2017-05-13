#pragma once

#include <Types.h>
#include <BWAPI/Race.h>

inline BWAPI::Race race_to_bw(Race race) {
    return BWAPI::Race(race.id);
}

inline Race race_from_bw(BWAPI::Race race) {
    Race self;
    self.id = race.getID();
    return self;
}
