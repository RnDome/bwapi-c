#pragma once

#include <Types.h>
#include <BWAPI/WeaponType.h>

inline BWAPI::WeaponType weapontype_to_bw(WeaponType type) {
    return BWAPI::WeaponType(type.id);
}

inline WeaponType weapontype_from_bw(BWAPI::WeaponType type) {
    WeaponType self;
    self.id = type.getID();
    return self;
}
