#pragma once

#include <Types.h>
#include <BWAPI/PlayerType.h>

inline BWAPI::PlayerType playertype_to_bw(PlayerType type) {
    return BWAPI::PlayerType(type.id);
}

inline PlayerType playertype_from_bw(BWAPI::PlayerType type) {
    PlayerType self;
    self.id = type.getID();
    return self;
}
