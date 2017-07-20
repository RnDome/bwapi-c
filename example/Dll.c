// mingw on linux: i686-w64-mingw32-gcc -mabi=ms -shared -o Dll.dll Dll.c -I../include -L. -lBWAPIC
// gcc   on linux: gcc -shared -fPIC -o Dll.so Dll.c -I../include -L. -lBWAPIC

#ifdef _WIN32
    #include <windows.h>
    #define DLLEXPORT __declspec(dllexport)
#else
    #define DLLEXPORT
#endif

#include <assert.h>
#include <stdlib.h>

#include <AIModule.h>
#include <Game.h>
#include <Iterator.h>
#include <Unit.h>
#include <Player.h>
#include <Event.h>

typedef struct BWAPI_Game BWAPI_Game; // BWAPI::Game
typedef struct BWAPI_AIModule BWAPI_AIModule; // BWAPI::AIModule

static Game* Broodwar;

typedef struct ExampleAIModule
{
    const AIModule_vtable* vtable_;

    const char* name;
} ExampleAIModule;

bool isMineralField(Unit* unit);
void drawWatermark(const int frame_count);
void printStartLocations();
void printEvent();
void registerEventHandler(Game* game);

void onStart(AIModule* self) {
    ExampleAIModule* module = (ExampleAIModule*) self;
    Game_sendText(Broodwar, "Hello from bwapi-c!");
    Game_sendText(Broodwar, "My name is %s", module->name);
}
void onEnd(AIModule* module, bool isWinner) {
    Game_sendText(Broodwar, "Game ended");
}

void onFrame(AIModule* self) {
    const int frame_count = Game_getFrameCount(Broodwar);
    CoordinateType CoordinateType_None = { .id = 0 };
    Game_drawText(Broodwar, CoordinateType_None, 10, 10, "Frame %d", frame_count);
    drawWatermark(frame_count);

    Player* const ai = Game_self(Broodwar);

    if (0 < frame_count && frame_count < 1000) {
        printEvent();
    }

    if (frame_count == 50) {
        printStartLocations();
    }

    if (frame_count == 150) {
        // registerEvent test
        Game_registerEvent(Broodwar, &registerEventHandler, NULL, 10, 0);
    }

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

                Iterator* const tqueue = (Iterator*) Unit_getTrainingQueue(unit);
                assert(tqueue);
                int x, y;
                for (x = 10, y = 20; Iterator_valid(tqueue); Iterator_next(tqueue), y += 10) {
                    UnitType* const unittype = (UnitType*) Iterator_get(tqueue);
                    assert(unittype);

                    Game_drawText(Broodwar, CoordinateType_None, x, y, "UnitType %d", unittype->id);
                }
                Iterator_release(tqueue);
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


bool isMineralField(Unit* unit) {
    int type_id = Unit_getType(unit).id;
    return type_id == 176  // Resource_Mineral_Field
           || type_id == 177  // Resource_Mineral_Field_Type_2
           || type_id == 178; // Resource_Mineral_Field_Type_3
}

void drawWatermark(const int frame_count) {
    if (20 <= frame_count && frame_count <= 200) {
        TextSize hugeSize = {.size = 3};
        Position position = {.x = 224, .y = 20};
        Game_setTextSize(Broodwar, hugeSize);
        Game_drawTextScreen(Broodwar, position, "BWAPIC demo");
    }
}

// the example of Game_getEvents
void printEvent() {
    Iterator* const events = (Iterator*) Game_getEvents(Broodwar);
    assert(events);

    // print only the first event because in OpenBW this code really spams too many in the console
    if (Iterator_valid(events)) {
        const Event e = * (Event*)Iterator_get(events);
        if (e.type.id != 2) { // MatchFrame
            Game_sendText(Broodwar, "EventType = (%d)", e.type.id);
            Game_sendText(Broodwar, "Position = (%d,%d)", e.position.x, e.position.y);
            if (e.player) {
                Game_sendText(Broodwar, "Player minerals = %d", Player_minerals(e.player));
            } else {
                Game_sendText(Broodwar, "Player = NULL");
            }
            if (e.unit) {
                Game_sendText(Broodwar, "Unit id = %d", Unit_getID(e.unit));
            } else {
                Game_sendText(Broodwar, "Unit = NULL");
            }
            BwString* txt = Event_getText(&e);
            Game_sendText(Broodwar, "Text = (%s)", BwString_data(txt));
            BwString_release(txt);
        }
    }
    Iterator_release(events);
}

// the example of Game_getStartLocations
void printStartLocations() {
    Iterator* const positions = (Iterator*) Game_getStartLocations(Broodwar);
    if (!Iterator_valid(positions)) {
        Game_sendText(Broodwar, "Start location iterator is empty.");
    }
    int i;
    for(i = 0; Iterator_valid(positions); Iterator_next(positions), i++) {
        const TilePosition tp = *(TilePosition*) Iterator_get(positions);
        Game_sendText(Broodwar, "Start location %d = (%d, %d)", i, tp.x, tp.y);
    }
    Iterator_release(positions);
}

void registerEventHandler(Game* game) {
    Game_sendText(game, "The message from registerEventHandler");
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

DLLEXPORT void gameInit(BWAPI_Game* game) {
    Broodwar = (Game*) game;
    BWAPIC_setGame(Broodwar);
}
DLLEXPORT BWAPI_AIModule* newAIModule() {
    ExampleAIModule* const module = (ExampleAIModule*) malloc( sizeof(ExampleAIModule) );
    module->name = "ExampleAIModule";
    module->vtable_ = &module_vtable;

    return (BWAPI_AIModule*) createAIModuleWrapper( (AIModule*) module );
}

#ifdef _WIN32
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
#endif
