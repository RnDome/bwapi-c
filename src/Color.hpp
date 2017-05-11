#pragma once

#include <Types.h>
#include <BWAPI/Color.h>

inline BWAPI::Color color_to_bw(Color color) {
    return BWAPI::Color(color.color);
}

inline Color color_from_bw(BWAPI::Color type) {
    Color self;
    self.color = type.getID();
    return self;
}
