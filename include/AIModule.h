#pragma once

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct AIModule
{
    void (*onStart)(struct AIModule* self);
    void (*onEnd)(struct AIModule* self, bool isWinner);
    void (*onFrame)(struct AIModule* self);
    void (*onSendText)(struct AIModule* self, const char* text);
    void (*onReceiveText)(struct AIModule* self, Player* player, const char* text);
    void (*onPlayerLeft)(struct AIModule* self, Player* player);
    void (*onNukeDetect)(struct AIModule* self, Position target);
    void (*onUnitDiscover)(struct AIModule* self, Unit* unit);
    void (*onUnitEvade)(struct AIModule* self, Unit* unit);
    void (*onUnitShow)(struct AIModule* self, Unit* unit);
    void (*onUnitHide)(struct AIModule* self, Unit* unit);
    void (*onUnitCreate)(struct AIModule* self, Unit* unit);
    void (*onUnitDestroy)(struct AIModule* self, Unit* unit);
    void (*onUnitMorph)(struct AIModule* self, Unit* unit);
    void (*onUnitRenegade)(struct AIModule* self, Unit* unit);
    void (*onSaveGame)(struct AIModule* self, const char* gameName);
    void (*onUnitComplete)(struct AIModule* self, Unit* unit);
} AIModule;

/* BWAPI::AIModule* */ void* createAIModuleWrapper(AIModule module);
void destroyAIModuleWrapper(/* BWAPI::AIModule* */ void* module);

#ifdef __cplusplus
} // extern "C"
#endif
