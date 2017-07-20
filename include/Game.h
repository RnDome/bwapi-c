#pragma once

#include <Types.h>

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

/// BWAPIC_setGame must be called from gameInit to initialize BWAPI::BroodwarPtr
void BWAPIC_setGame(Game* game);
Game* BWAPIC_getGame();

ForceIterator* Game_getForces(Game* self);
PlayerIterator* Game_getPlayers(Game* self);
UnitIterator* Game_getAllUnits(Game* self);
UnitIterator* Game_getMinerals(Game* self);
UnitIterator* Game_getGeysers(Game* self);
UnitIterator* Game_getNeutralUnits(Game* self);
UnitIterator* Game_getStaticMinerals(Game* self);
UnitIterator* Game_getStaticGeysers(Game* self);
UnitIterator* Game_getStaticNeutralUnits(Game* self);
BulletIterator* Game_getBullets(Game* self);
PositionIterator* Game_getNukeDots(Game* self);
EventIterator* Game_getEvents(Game* self);
Force* Game_getForce(Game* self, int forceID);
Player* Game_getPlayer(Game* self, int playerID);
Unit* Game_getUnit(Game* self, int unitID);
Unit* Game_indexToUnit(Game* self, int unitIndex);
Region* Game_getRegion(Game* self, int regionID);
GameType Game_getGameType(Game* self);
int Game_getLatency(Game* self);
int Game_getFrameCount(Game* self);
int Game_getReplayFrameCount(Game* self);
int Game_getFPS(Game* self);
double Game_getAverageFPS(Game* self);
Position Game_getMousePosition(Game* self);
bool Game_getMouseState(Game* self, MouseButton button);
bool Game_getKeyState(Game* self, KeyButton key);
Position Game_getScreenPosition(Game* self);
void Game_setScreenPosition(Game* self, Position p);
void Game_pingMinimap(Game* self, Position p);
bool Game_isFlagEnabled(Game* self, int flag);
void Game_enableFlag(Game* self, int flag);
UnitIterator* Game_getUnitsOnTile(Game* self, TilePosition tile, UnaryUnitFilter pred);
UnitIterator* Game_getUnitsInRectangle(Game* self, Position topLeft, Position bottomRight, UnaryUnitFilter pred);
UnitIterator* Game_getUnitsInRadius(Game* self, Position center, int radius, UnaryUnitFilter pred);
Unit* Game_getClosestUnit(Game* self, Position center, UnaryUnitFilter pred, int radius);
Unit* Game_getClosestUnitInRectangle(Game* self, Position center, UnaryUnitFilter pred, int left, int top, int right, int bottom);
Unit* Game_getBestUnit(Game* self, BestUnitFilter best, UnaryUnitFilter pred, Position center, int radius);

Error Game_getLastError(Game* self);
bool Game_setLastError(Game* self, Error e);

int Game_mapWidth(Game* self);
int Game_mapHeight(Game* self);
BwString* Game_mapFileName(Game* self);
BwString* Game_mapPathName(Game* self);
BwString* Game_mapName(Game* self);
BwString* Game_mapHash(Game* self);
bool Game_isWalkable(Game* self, WalkPosition position);
int  Game_getGroundHeight(Game* self, TilePosition position);
bool Game_isBuildable(Game* self, TilePosition position, bool includeBuildings);
bool Game_isVisible(Game* self, TilePosition position);
bool Game_isExplored(Game* self, TilePosition position);
bool Game_hasCreep(Game* self, TilePosition position);
bool Game_hasPowerPrecise(Game* self, Position position, UnitType unitType);
bool Game_hasPower(Game* self, TilePosition position, UnitType unitType);
bool Game_hasPowerWH(Game* self, TilePosition position, int tileWidth, int tileHeight, UnitType unitType);
bool Game_canBuildHere(Game* self, TilePosition position, UnitType type, Unit* builder, bool checkExplored);
bool Game_canMake(Game* self, UnitType type, Unit* builder);
bool Game_canResearch(Game* self, TechType type, Unit* unit, bool checkCanIssueCommandType);
bool Game_canUpgrade(Game* self, UpgradeType type, Unit* unit, bool checkCanIssueCommandType);
TilePositionIterator* Game_getStartLocations(Game* self);
void Game_printf(Game* self, const char* format, ...);
void Game_vPrintf(Game* self, const char* format, va_list args);
void Game_sendText(Game* self, const char* format, ...);
void Game_vSendText(Game* self, const char* format, va_list args);
void Game_sendTextEx(Game* self, bool toAllies, const char* format, ...);
void Game_vSendTextEx(Game* self, bool toAllies, const char* format, va_list args);
bool Game_isInGame(Game* self);
bool Game_isMultiplayer(Game* self);
bool Game_isBattleNet(Game* self);
bool Game_isPaused(Game* self);
bool Game_isReplay(Game* self);
void Game_pauseGame(Game* self);
void Game_resumeGame(Game* self);
void Game_leaveGame(Game* self);
void Game_restartGame(Game* self);
void Game_setLocalSpeed(Game* self, int speed);

bool Game_issueCommand(Game* self, UnitIterator* units, UnitCommand command);

UnitIterator* Game_getSelectedUnits(Game* self);

Player* Game_self(Game* self);
Player* Game_enemy(Game* self);
Player* Game_neutral(Game* self);

PlayerIterator* Game_allies(Game* self);
PlayerIterator* Game_enemies(Game* self);
PlayerIterator* Game_observers(Game* self);

void Game_setTextSize(Game* self, TextSize size);
void Game_vDrawText(Game* self, CoordinateType ctype, int x, int y, const char* format, va_list args);
void Game_drawText(Game* self, CoordinateType ctype, int x, int y, const char* format, ...);
void Game_drawTextMap(Game* self, Position p, const char* format, ...);
void Game_drawTextMouse(Game* self, Position p, const char* format, ...);
void Game_drawTextScreen(Game* self, Position p, const char* format, ...);

void Game_drawBox(Game* self, CoordinateType ctype, int left, int top, int right, int bottom, Color color, bool isSolid);
void Game_drawBoxMap(Game* self, Position leftTop, Position rightBottom, Color color, bool isSolid);
void Game_drawBoxMouse(Game* self, Position leftTop, Position rightBottom, Color color, bool isSolid);
void Game_drawBoxScreen(Game* self, Position leftTop, Position rightBottom, Color color, bool isSolid);
void Game_drawTriangle(Game* self, CoordinateType ctype, int ax, int ay, int bx, int by, int cx, int cy, Color color, bool isSolid);
void Game_drawTriangleMap(Game* self, Position a, Position b, Position c, Color color, bool isSolid);
void Game_drawTriangleMouse(Game* self, Position a, Position b, Position c, Color color, bool isSolid);
void Game_drawTriangleScreen(Game* self, Position a, Position b, Position c, Color color, bool isSolid);
void Game_drawCircle(Game* self, CoordinateType ctype, int x, int y, int radius, Color color, bool isSolid);
void Game_drawCircleMap(Game* self, Position p, int radius, Color color, bool isSolid);
void Game_drawCircleMouse(Game* self, Position p, int radius, Color color, bool isSolid);
void Game_drawCircleScreen(Game* self, Position p, int radius, Color color, bool isSolid);
void Game_drawEllipse(Game* self, CoordinateType ctype, int x, int y, int xrad, int yrad, Color color, bool isSolid);
void Game_drawEllipseMap(Game* self, Position p, int xrad, int yrad, Color color, bool isSolid);
void Game_drawEllipseMouse(Game* self, Position p, int xrad, int yrad, Color color, bool isSolid);
void Game_drawEllipseScreen(Game* self, Position p, int xrad, int yrad, Color color, bool isSolid);
void Game_drawDot(Game* self, CoordinateType ctype, int x, int y, Color color);
void Game_drawDotMap(Game* self, Position p, Color color);
void Game_drawDotMouse(Game* self, Position p, Color color);
void Game_drawDotScreen(Game* self, Position p, Color color);
void Game_drawLine(Game* self, CoordinateType ctype, int x1, int y1, int x2, int y2, Color color);
void Game_drawLineMap(Game* self, Position a, Position b, Color color);
void Game_drawLineMouse(Game* self, Position a, Position b, Color color);
void Game_drawLineScreen(Game* self, Position a, Position b, Color color);
int Game_getLatencyFrames(Game* self);
int Game_getLatencyTime(Game* self);
int Game_getRemainingLatencyFrames(Game* self);
int Game_getRemainingLatencyTime(Game* self);
int Game_getRevision(Game* self);
int Game_getClientVersion(Game* self);
bool Game_isDebug(Game* self);
bool Game_isLatComEnabled(Game* self);
void Game_setLatCom(Game* self, bool isEnabled);
bool Game_isGUIEnabled(Game* self);
void Game_setGUI(Game* self, bool enabled);
int Game_getInstanceNumber(Game* self);
int Game_getAPM(Game* self, bool includeSelects);
bool Game_setMap(Game* self, const char* mapFileName);
void Game_setFrameSkip(Game* self, int frameSkip);
bool Game_hasPath(Game* self, Position source, Position destination);
bool Game_setAlliance(Game* self, Player* player, bool allied, bool alliedVictory);
bool Game_setVision(Game* self, Player* player, bool enabled);
int Game_elapsedTime(Game* self);
void Game_setCommandOptimizationLevel(Game* self, int level);
int Game_countdownTimer(Game* self);
RegionIterator* Game_getAllRegions(Game* self);
Region* Game_getRegionAt(Game* self, Position position);
int Game_getLastEventTime(Game* self);
bool Game_setRevealAll(Game* self, bool reveal);
TilePosition Game_getBuildLocation(Game* self, UnitType type, TilePosition desiredPosition, int maxRange, bool creep);
int Game_getDamageFrom(Game* self, UnitType fromType, UnitType toType, Player* fromPlayer, Player* toPlayer);
int Game_getDamageTo(Game* self, UnitType toType, UnitType fromType, Player* toPlayer, Player* fromPlayer);
unsigned Game_getRandomSeed(Game* self);
void Game_registerEvent(Game* self, void (* const action)(Game*), bool (* const condition)(Game*), int timesToRun, int framesToCheck);

#ifdef __cplusplus
} // extern "C"
#endif
