#include <Force.h>
#include <BwString.h>
#include <BWAPI/Force.h>

int Force_getID(Force* self) {
    return reinterpret_cast<BWAPI::Force>(self)->getID();
}

BwString* Force_getName(Force* self) {
    const std::string& name = reinterpret_cast<BWAPI::Force>(self)->getName();
    return BwString_new(name.c_str(), name.length());
}
