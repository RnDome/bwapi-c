// i686-w64-mingw32-g++ -std=c++11 -mabi=ms -shared -o Dll.dll Dll.cpp -I../include -L. -lBWAPIC

#include <windows.h>
#include <assert.h>

#include <AIModule.h>
#include <Game.h>
#include <Iterator.h>
#include <Unit.h>

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
void onFrame(AIModule* module) {
    Iterator* const iter = reinterpret_cast<Iterator*>(Game_getAllUnits(Broodwar));
    assert(iter);

    for (; Iterator_valid(iter); Iterator_next(iter)) {
        Unit* const unit = reinterpret_cast<Unit*>(Iterator_get(iter));
        assert(unit);

        const int id = Unit_getID(unit);
        const Position position = Unit_getPosition(unit);
        Game_sendText(Broodwar, "Unit %d x: %d, y: %d", id, position.x, position.y);
    }

    Iterator_release(iter);
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
