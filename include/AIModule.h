#pragma once

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// Declare your own module:
///
/// typedef struct MyModule {
///  const AIModule_vtable* vtable_;
///  int my_field;
///  ...
/// };
///
/// Create vtable:
///
/// void onStart(AIModule*) { }
/// static AIModule_vtable my_vtable = { onStart, pointer to functions... };
///
/// Set vtable:
///
/// MyModule module;
/// module.vtable = &my_vtable;
///
/// Wrap your module into a BWAPI::AIModule:
///  /* BWAPI::AIModule* */ void* wrapper_ptr = createAIModuleWrapper(&module);
///
/// createAIModuleWrapper does not own your module
///
/// Now your wrapper_ptr can be passed inside the game on call to newAIModule from dll

/// NOTE Using MS extension you may derive from AIModule
/// In MSVC enabled by default;
/// In gcc: add flag -fms-extensions
///
/// Example:
///  typedef struct MyModule {
///   truct AIModule; // base
///   int my_field;
///   ...
///  } MyModule;

typedef struct AIModule_vtable AIModule_vtable;
typedef struct AIModule {
    const AIModule_vtable* vtable;
} AIModule;

struct AIModule_vtable
{
    void (*onStart)(AIModule* module);
    void (*onEnd)(AIModule* module, bool isWinner);
    void (*onFrame)(AIModule* module);
    void (*onSendText)(AIModule* module, const char* text);
    void (*onReceiveText)(AIModule* module, Player* player, const char* text);
    void (*onPlayerLeft)(AIModule* module, Player* player);
    void (*onNukeDetect)(AIModule* module, Position target);
    void (*onUnitDiscover)(AIModule* module, Unit* unit);
    void (*onUnitEvade)(AIModule* module, Unit* unit);
    void (*onUnitShow)(AIModule* module, Unit* unit);
    void (*onUnitHide)(AIModule* module, Unit* unit);
    void (*onUnitCreate)(AIModule* module, Unit* unit);
    void (*onUnitDestroy)(AIModule* module, Unit* unit);
    void (*onUnitMorph)(AIModule* module, Unit* unit);
    void (*onUnitRenegade)(AIModule* module, Unit* unit);
    void (*onSaveGame)(AIModule* module, const char* gameName);
    void (*onUnitComplete)(AIModule* module, Unit* unit);
};

/* BWAPI::AIModule* */ void* createAIModuleWrapper(AIModule* module);
void destroyAIModuleWrapper(/* BWAPI::AIModule* */ void* module);

#ifdef __cplusplus
} // extern "C"
#endif
