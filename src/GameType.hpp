#pragma once

#include <Types.h>
#include <BWAPI/GameType.h>

inline BWAPI::GameType gametype_to_bw(GameType type) {
    return BWAPI::GameType(type.id);
}

inline GameType gametype_from_bw(BWAPI::GameType type) {
    GameType self;
    self.id = type.getID();
    return self;
}
