#pragma once

#include <Types.h>
#include <BWAPI/Input.h>

inline BWAPI::Key keybutton_to_bw(KeyButton key) {
    return static_cast<BWAPI::Key>(key.id);
}

inline KeyButton keybutton_from_bw(BWAPI::Key key) {
    KeyButton self;
    self.id = static_cast<int>(key);
    return self;
}

inline BWAPI::MouseButton mousebutton_to_bw(MouseButton button) {
    return static_cast<BWAPI::MouseButton>(button.id);
}

inline MouseButton mousebutton_from_bw(BWAPI::MouseButton button) {
    MouseButton self;
    self.id = static_cast<int>(button);
    return self;
}
