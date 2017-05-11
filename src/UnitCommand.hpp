#pragma once

#include <Types.h>
#include <BWAPI/UnitCommand.h>
#include <BWAPI/UnitCommandType.h>

inline BWAPI::UnitCommandType unitcommandtype_to_bw(UnitCommandType type) {
    return BWAPI::UnitCommandType(type.id);
}

inline UnitCommandType unitcommandtype_from_bw(BWAPI::UnitCommandType type) {
    UnitCommandType self;
    self.id = type.getID();
    return self;
}

inline BWAPI::UnitCommand unitcommand_to_bw(UnitCommand command) {
    return BWAPI::UnitCommand(reinterpret_cast<BWAPI::Unit>(command.unit), unitcommandtype_to_bw(command.type), reinterpret_cast<BWAPI::Unit>(command.target), command.x, command.y, command.extra);
}

inline UnitCommand unitcommand_from_bw(BWAPI::UnitCommand command) {
    UnitCommand self;
    self.unit = reinterpret_cast<Unit*>(command.unit);
    self.type = unitcommandtype_from_bw(command.type);
    self.target = reinterpret_cast<Unit*>(command.target);
    self.x = command.x;
    self.y = command.y;
    self.extra = command.extra;
    return self;
}
