#include <Force.h>
#include <BwString.h>

#include "IteratorImpl.hpp"

int Force_getID(Force* self) {
    return reinterpret_cast<BWAPI::Force>(self)->getID();
}

BwString* Force_getName(Force* self) {
    const std::string& name = reinterpret_cast<BWAPI::Force>(self)->getName();
    return BwString_new(name.c_str(), name.length());
}

PlayerIterator* Force_getPlayers(Force* self) {
    auto&& players = reinterpret_cast<BWAPI::Force>(self)->getPlayers();
    return into_iter<PlayerIterator>(std::move(players));
}
