#pragma once

#include <Types.h>
#include <BWAPI/BulletType.h>

inline BWAPI::BulletType bullettype_to_bw(BulletType type) {
    return BWAPI::BulletType(type.id);
}

inline BulletType bullettype_from_bw(BWAPI::BulletType type) {
    BulletType self;
    self.id = type.getID();
    return self;
}
