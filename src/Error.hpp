#pragma once

#include <Types.h>
#include <BWAPI/Error.h>

inline BWAPI::Error error_to_bw(Error error) {
    return BWAPI::Error(error.id);
}

inline Error error_from_bw(BWAPI::Error error) {
    Error self;
    self.id = error.getID();
    return self;
}
