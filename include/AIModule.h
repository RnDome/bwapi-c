#pragma once

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct AIModule
{
    typedef void (*onStart_t)(AIModule* self);
    typedef void (*onEnd_t)(AIModule* self, bool isWinner);
    typedef void (*onFrame_t)(AIModule* self);
    typedef void (*onSendText_t)(AIModule* self, const char* text);
    typedef void (*onReceiveText_t)(AIModule* self, Player* player, const char* text);
    typedef void (*onPlayerLeft_t)(AIModule* self, Player* player);
    typedef void (*onNukeDetect_t)(AIModule* self, Position target);
    typedef void (*onUnitDiscover_t)(AIModule* self, Unit* unit);
    typedef void (*onUnitEvade_t)(AIModule* self, Unit* unit);
    typedef void (*onUnitShow_t)(AIModule* self, Unit* unit);
    typedef void (*onUnitHide_t)(AIModule* self, Unit* unit);
    typedef void (*onUnitCreate_t)(AIModule* self, Unit* unit);
    typedef void (*onUnitDestroy_t)(AIModule* self, Unit* unit);
    typedef void (*onUnitMorph_t)(AIModule* self, Unit* unit);
    typedef void (*onUnitRenegade_t)(AIModule* self, Unit* unit);
    typedef void (*onSaveGame_t)(AIModule* self, const char* gameName);
    typedef void (*onUnitComplete_t)(AIModule* self, Unit* unit);

    onStart_t onStart;
    onEnd_t onEnd;
    onFrame_t onFrame;
    onSendText_t onSendText;
    onReceiveText_t onReceiveText;
    onPlayerLeft_t onPlayerLeft;
    onNukeDetect_t onNukeDetect;
    onUnitDiscover_t onUnitDiscover;
    onUnitEvade_t onUnitEvade;
    onUnitShow_t onUnitShow;
    onUnitHide_t onUnitHide;
    onUnitCreate_t onUnitCreate;
    onUnitDestroy_t onUnitDestroy;
    onUnitMorph_t onUnitMorph;
    onUnitRenegade_t onUnitRenegade;
    onSaveGame_t onSaveGame;
    onUnitComplete_t onUnitComplete;

} AIModule;

/* BWAPI::AIModule* */ void* createAIModuleWrapper(AIModule module);
void destroyAIModuleWrapper(/* BWAPI::AIModule* */ void* module);

#ifdef __cplusplus
} // extern "C"
#endif
