#pragma once

#include <Types.h>
#include <BWAPI/Color.h>

BWAPI::Color color_to_bw(Color color) {
    return BWAPI::Color(color.color);
}

Color color_from_bw(BWAPI::Color type) {
    Color self;
    self.color = type.getID();
    return self;
}
