#pragma once

#include <Types.h>
#include <BWAPI/Position.h>

inline BWAPI::Position position_to_bw(Position position) {
    return BWAPI::Position(position.x, position.y);
}

inline Position position_from_bw(BWAPI::Position position) {
    Position self;
    self.x = position.x;
    self.y = position.y;
    return self;
}

inline BWAPI::TilePosition tileposition_to_bw(TilePosition position) {
    return BWAPI::TilePosition(position.x, position.y);
}

inline TilePosition tileposition_from_bw(BWAPI::TilePosition position) {
    TilePosition self;
    self.x = position.x;
    self.y = position.y;
    return self;
}

inline BWAPI::WalkPosition walkposition_to_bw(WalkPosition position) {
    return BWAPI::WalkPosition(position.x, position.y);
}

inline WalkPosition walkposition_from_bw(BWAPI::WalkPosition position) {
    WalkPosition self;
    self.x = position.x;
    self.y = position.y;
    return self;
}
