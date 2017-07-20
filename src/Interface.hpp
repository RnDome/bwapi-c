#pragma once

#include <Types.h>
#include <BwString.h>
#include <BWAPI.h>
#include "Cast.hpp"

/**
 * @tparam TX - some external type, from <i>Types.h</i>:
 * <ul>
 *   <li/> Game
 *   <li/> Unit
 *   <li/> Bullet
 *   <li/> Region
 *   <li/> Player
 *   <li/> Force
 * </ul>
 */
template<typename TX>
void Interface_registerEvent(
    TX* self,
    void (* const action)(TX*),
    bool (* const condition)(TX*),
    int timesToRun,
    int framesToCheck
) {
    // deduce the corresponding BWAPI type for the external type
    typedef typename CastRev<TX*>::Type::BwType BW;
    auto a0 = [action](BW self1) {
        (*action)(cast_from_bw(self1));
    };
    // condition can be null
    if (condition != nullptr) {
        auto c0 = [condition](BW self2) {
            return (*condition)(cast_from_bw(self2));
        };
        reinterpret_cast<BW>(self)->registerEvent(a0, c0, timesToRun, framesToCheck);
    } else {
        reinterpret_cast<BW>(self)->registerEvent(a0, nullptr, timesToRun, framesToCheck);
    }
}
