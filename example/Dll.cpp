// i686-w64-mingw32-g++ -std=c++11 -mabi=ms -shared -o Dll.dll Dll.cpp -I../include -L. -lBWAPIC

#include <windows.h>
#include <assert.h>

#include <AIModule.h>
#include <Game.h>
#include <Iterator.h>
#include <Unit.h>
#include <Player.h>

namespace BWAPI {
    class Game;
    class AIModule;
}

static Game* Broodwar;

typedef struct ExampleAIModule
{
    const AIModule_vtable* vtable_;

    const char* name;
} ExampleModule;

void onStart(AIModule* self) {
    ExampleModule* module = reinterpret_cast<ExampleModule*>( self );
    Game_sendText(Broodwar, "Hello from AIModule!");
    Game_sendText(Broodwar, "My name is %s", module->name);
}
void onEnd(AIModule* module, bool isWinner) {
    Game_sendText(Broodwar, "Game ended");
}

void onFrame(AIModule* self) {
    const int frame_count = Game_getFrameCount(Broodwar);
    Game_drawText(Broodwar, CoordinateType {0}, 10, 10, "Frame %d", frame_count);

    Player* const ai = Game_self(Broodwar);

    Iterator* const units = reinterpret_cast<Iterator*>(Player_getUnits(ai));
    assert(units);

    for (; Iterator_valid(units); Iterator_next(units)) {
        Unit* const unit = reinterpret_cast<Unit*>(Iterator_get(units));
        assert(unit);

        const UnitType type = Unit_getType(unit);

        switch (type.id) {
            case 7:  // SCV
            case 41: // Drone
            case 64: // Probe
                if (Unit_isIdle(unit)) {
                    if (Unit_isCarryingGas(unit) || Unit_isCarryingMinerals(unit)) {
                        Unit_returnCargo(unit, false);
                    } else {
                        Iterator* const minerals = reinterpret_cast<Iterator*>(Game_getMinerals(Broodwar));
                        assert(minerals);

                        Unit* closest_mineral = nullptr;
                        for (; Iterator_valid(minerals); Iterator_next(minerals)) {
                            Unit* const mineral = reinterpret_cast<Unit*>(Iterator_get(minerals));
                            assert(mineral);

                            if (!closest_mineral || Unit_getDistance_Unit(unit, mineral) < Unit_getDistance_Unit(unit, closest_mineral))
                                closest_mineral = mineral;
                        }

                        if (closest_mineral)
                            Unit_rightClick_Unit(unit, closest_mineral, false);

                        Iterator_release(minerals);
                    }
                }
                break;

            case 106: // Terran_Command_Center
                Unit_train(unit, UnitType{7}); // SCV
                break;

            case 154: // Protoss_Nexus
                Unit_train(unit, UnitType{64}); // Probe
                break;

            case 131: // Zerg_Hatchery
            case 132: // Zerg_Lair
            case 133: // Zerg_Hive
                Unit_train(unit, UnitType{41}); // Drone
                break;

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

extern "C"
{
    __declspec(dllexport) void gameInit(BWAPI::Game* BroodwarPtr) {
        Broodwar = reinterpret_cast<Game*>(BroodwarPtr);
    }
    __declspec(dllexport) BWAPI::AIModule* newAIModule() {
        ExampleModule module;
        module.name = "ExampleModule";
        module.vtable_ = &module_vtable;

        return reinterpret_cast<BWAPI::AIModule*>( createAIModuleWrapper(reinterpret_cast<AIModule*>(&module), sizeof(module)) );
    }
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
