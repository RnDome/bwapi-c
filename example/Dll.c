// i686-w64-mingw32-gcc -mabi=ms -shared -o Dll.dll Dll.c -I../include -L. -lBWAPIC

#include <windows.h>
#include <assert.h>
#include <stdlib.h>

#include <AIModule.h>
#include <Game.h>
#include <Iterator.h>
#include <Unit.h>
#include <Player.h>

typedef struct BWAPI_Game BWAPI_Game; // BWAPI::Game
typedef struct BWAPI_AIModule BWAPI_AIModule; // BWAPI::AIModule

static Game* Broodwar;

typedef struct ExampleAIModule
{
    const AIModule_vtable* vtable_;

    const char* name;
} ExampleAIModule;

void onStart(AIModule* self) {
    ExampleAIModule* module = (ExampleAIModule*) self;
    Game_sendText(Broodwar, "Hello from AIModule!");
    Game_sendText(Broodwar, "My name is %s", module->name);
}
void onEnd(AIModule* module, bool isWinner) {
    Game_sendText(Broodwar, "Game ended");
}

bool isMineralField(Unit* unit) {
    int type_id = Unit_getType(unit).id;
    return type_id == 176  // Resource_Mineral_Field
        || type_id == 177  // Resource_Mineral_Field_Type_2
        || type_id == 178; // Resource_Mineral_Field_Type_3
}

void onFrame(AIModule* self) {
    const int frame_count = Game_getFrameCount(Broodwar);
    CoordinateType CoordinateType_None = { .id = 0 };
    Game_drawText(Broodwar, CoordinateType_None, 10, 10, "Frame %d", frame_count);

    Player* const ai = Game_self(Broodwar);

    Iterator* const units = (Iterator*) Player_getUnits(ai);
    assert(units);

    for (; Iterator_valid(units); Iterator_next(units)) {
        Unit* const unit = (Unit*) Iterator_get(units);
        assert(unit);

        if ( !Unit_exists(unit) )
            continue;

        const UnitType type = Unit_getType(unit);

        switch (type.id) {
            case 7:  // SCV
            case 41: // Drone
            case 64: // Probe
                if (Unit_isIdle(unit)) {
                    if (Unit_isCarryingGas(unit) || Unit_isCarryingMinerals(unit)) {
                        Unit_returnCargo(unit, false);
                    } else {
                        Unit* const closest_mineral = Unit_getClosestUnit(unit, &isMineralField, /*radius*/ 999999);

                        if (closest_mineral)
                            Unit_rightClick_Unit(unit, closest_mineral, false);
                    }
                }
                break;

            case 106: {// Terran_Command_Center
                UnitType SCV = {.id = 7 };
                Unit_train(unit, SCV);
            } break;

            case 154: { // Protoss_Nexus
                UnitType Probe = {.id = 64 };
                Unit_train(unit, Probe);
            } break;

            case 131:   // Zerg_Hatchery
            case 132:   // Zerg_Lair
            case 133: { // Zerg_Hive
                UnitType Drone = {.id = 41 };
                Unit_train(unit, Drone);
            } break;

        }
    }

    Iterator_release(units);
}
void onSendText(AIModule* module, const char* text) {}
void onReceiveText(AIModule* module, Player* player, const char* text) {}
void onPlayerLeft(AIModule* module, Player* player) {}
void onNukeDetect(AIModule* module, Position target) {}
void onUnitDiscover(AIModule* module, Unit* unit) {}
void onUnitEvade(AIModule* module, Unit* unit) {}
void onUnitShow(AIModule* module, Unit* unit) {}
void onUnitHide(AIModule* module, Unit* unit) {}
void onUnitCreate(AIModule* module, Unit* unit) {}
void onUnitDestroy(AIModule* module, Unit* unit) {}
void onUnitMorph(AIModule* module, Unit* unit) {}
void onUnitRenegade(AIModule* module, Unit* unit) {}
void onSaveGame(AIModule* module, const char* gameName) {}
void onUnitComplete(AIModule* module, Unit* unit) {}

static AIModule_vtable module_vtable = {
    onStart,
    onEnd,
    onFrame,
    onSendText,
    onReceiveText,
    onPlayerLeft,
    onNukeDetect,
    onUnitDiscover,
    onUnitEvade,
    onUnitShow,
    onUnitHide,
    onUnitCreate,
    onUnitDestroy,
    onUnitMorph,
    onUnitRenegade,
    onSaveGame,
    onUnitComplete
};

__declspec(dllexport) void gameInit(BWAPI_Game* BroodwarPtr) {
    Broodwar = (Game*) BroodwarPtr;
}
__declspec(dllexport) BWAPI_AIModule* newAIModule() {
    ExampleAIModule* const module = (ExampleAIModule*) malloc( sizeof(ExampleAIModule) );
    module->name = "ExampleAIModule";
    module->vtable_ = &module_vtable;

    return (BWAPI_AIModule*) createAIModuleWrapper( (AIModule*) module );
}

BOOL APIENTRY DllMain( HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
