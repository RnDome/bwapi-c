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

void onStart(AIModule* self) {
    Game_sendText(Broodwar, "Hello from AIModule!");
}

void onEnd(AIModule* self, bool isWinner) {
    Game_sendText(Broodwar, "Game ended");
}

void onFrame(AIModule* self) {
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

void onSendText(AIModule* self, const char* text) {}
void onReceiveText(AIModule* self, Player* player, const char* text) {}
void onPlayerLeft(AIModule* self, Player* player) {}
void onNukeDetect(AIModule* self, Position target) {}
void onUnitDiscover(AIModule* self, Unit* unit) {}
void onUnitEvade(AIModule* self, Unit* unit) {}
void onUnitShow(AIModule* self, Unit* unit) {}
void onUnitHide(AIModule* self, Unit* unit) {}
void onUnitCreate(AIModule* self, Unit* unit) {}
void onUnitDestroy(AIModule* self, Unit* unit) {}
void onUnitMorph(AIModule* self, Unit* unit) {}
void onUnitRenegade(AIModule* self, Unit* unit) {}
void onSaveGame(AIModule* self, const char* gameName) {}
void onUnitComplete(AIModule* self, Unit* unit) {}


extern "C"
{
    __declspec(dllexport) void gameInit(BWAPI::Game* BroodwarPtr) {
        Broodwar = reinterpret_cast<Game*>(BroodwarPtr);
    }
    __declspec(dllexport) BWAPI::AIModule* newAIModule() {
        AIModule module;
        module.onStart = onStart;
        module.onEnd = onEnd;
        module.onFrame = onFrame;
        module.onSendText = onSendText;
        module.onReceiveText = onReceiveText;
        module.onPlayerLeft = onPlayerLeft;
        module.onNukeDetect = onNukeDetect;
        module.onUnitDiscover = onUnitDiscover;
        module.onUnitEvade = onUnitEvade;
        module.onUnitShow = onUnitShow;
        module.onUnitHide = onUnitHide;
        module.onUnitCreate = onUnitCreate;
        module.onUnitDestroy = onUnitDestroy;
        module.onUnitMorph = onUnitMorph;
        module.onUnitRenegade = onUnitRenegade;
        module.onSaveGame = onSaveGame;
        module.onUnitComplete = onUnitComplete;

        return reinterpret_cast<BWAPI::AIModule*>( createAIModuleWrapper(module) );
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
