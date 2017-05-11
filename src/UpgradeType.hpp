#pragma once

#include <Types.h>
#include <BWAPI/UpgradeType.h>

inline BWAPI::UpgradeType upgradetype_to_bw(UpgradeType type) {
    return BWAPI::UpgradeType(type.id);
}

inline UpgradeType upgradetype_from_bw(BWAPI::UpgradeType type) {
    UpgradeType self;
    self.id = type.getID();
    return self;
}
