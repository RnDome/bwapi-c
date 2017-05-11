#pragma once

#include <Types.h>

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

// TODO const Forceset& getForces();
// TODO const Playerset& getPlayers();
// TODO const Unitset& getAllUnits();
// TODO const Unitset& getMinerals();
// TODO const Unitset& getGeysers();
// TODO const Unitset& getNeutralUnits();
// TODO const Unitset& getStaticMinerals();
// TODO const Unitset& getStaticGeysers();
// TODO const Unitset& getStaticNeutralUnits();
// TODO const Bulletset& getBullets();
// TODO const Position::list& getNukeDots();
// TODO const std::list< Event >& getEvents();
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
// TODO Unitset getUnitsOnTile(int tileX, int tileY, const UnitFilter &pred);
// TODO Unitset getUnitsOnTile(BWAPI::TilePosition tile, const UnitFilter &pred);
// TODO Unitset getUnitsInRectangle(int left, int top, int right, int bottom, const UnitFilter &pred);
// TODO Unitset getUnitsInRectangle(BWAPI::Position topLeft, BWAPI::Position bottomRight, const UnitFilter &pred);
// TODO Unitset getUnitsInRadius(int x, int y, int radius, const UnitFilter &pred);
// TODO Unitset getUnitsInRadius(BWAPI::Position center, int radius, const UnitFilter &pred);
// TODO Unit getClosestUnit(Position center, const UnitFilter &pred, int radius = 999999);
// TODO Unit getClosestUnitInRectangle(Position center, const UnitFilter &pred, int left, int top, int right = 999999, int bottom = 999999);
// TODO Unit getBestUnit(const BestUnitFilter &best, const UnitFilter &pred, Position center = Positions::Origin, int radius = 999999);
// TODO Error getLastError();

//TODO bool setLastError(BWAPI::Error e = Errors::None);
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
// TODO virtual const TilePosition::list& getStartLocations();
void Game_printf(Game* self, const char *format, ...);
void Game_vPrintf(Game* self, const char *format, va_list args);
void Game_sendText(Game* self, const char *format, ...);
void Game_vSendText(Game* self, const char *format, va_list args);
void Game_sendTextEx(Game* self, bool toAllies, const char *format, ...);
void Game_vSendTextEx(Game* self, bool toAllies, const char *format, va_list args);
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

//TODO virtual bool issueCommand(const Unitset& units, UnitCommand command);

//TODO virtual const Unitset& getSelectedUnits();
Player* Game_self(Game* self);
Player* Game_enemy(Game* self);
Player* Game_neutral(Game* self);

// TODO virtual Playerset& allies();
// TODO virtual Playerset& enemies();
// TODO virtual Playerset& observers();
// TODO void setTextSize(Text::Size::Enum size);
// TODO void vDrawText(CoordinateType::Enum ctype, int x, int y, const char *format, va_list arg);
// TODO void drawText(CoordinateType::Enum ctype, int x, int y, const char *format, ...);
// TODO void Game_drawTextMap(Game* self, Position p, const char *format, ...);
// TODO void Game_drawTextMouse(Game* self, Position p, const char *format, ...);
// TODO void Game_drawTextScreen(Game* self, Position p, const char *format, ...);
// TODO void drawBox(CoordinateType::Enum ctype, int left, int top, int right, int bottom, Color color, bool isSolid);
void Game_drawBoxMap(Game* self, Position leftTop, Position rightBottom, Color color, bool isSolid);
void Game_drawBoxMouse(Game* self, Position leftTop, Position rightBottom, Color color, bool isSolid);
void Game_drawBoxScreen(Game* self, Position leftTop, Position rightBottom, Color color, bool isSolid);
// TODO void drawTriangle(CoordinateType::Enum ctype, int ax, int ay, int bx, int by, int cx, int cy, Color color, bool isSolid);
void Game_drawTriangleMap(Game* self, Position a, Position b, Position c, Color color, bool isSolid);
void Game_drawTriangleMouse(Game* self, Position a, Position b, Position c, Color color, bool isSolid);
void Game_drawTriangleScreen(Game* self, Position a, Position b, Position c, Color color, bool isSolid);
// TODO void drawCircle(CoordinateType::Enum ctype, int x, int y, int radius, Color color, bool isSolid);
void Game_drawCircleMap(Game* self, Position p, int radius, Color color, bool isSolid);
void Game_drawCircleMouse(Game* self, Position p, int radius, Color color, bool isSolid);
void Game_drawCircleScreen(Game* self, Position p, int radius, Color color, bool isSolid);
// TODO void drawEllipse(CoordinateType::Enum ctype, int x, int y, int xrad, int yrad, Color color, bool isSolid);
void Game_drawEllipseMap(Game* self, Position p, int xrad, int yrad, Color color, bool isSolid);
void Game_drawEllipseMouse(Game* self, Position p, int xrad, int yrad, Color color, bool isSolid);
void Game_drawEllipseScreen(Game* self, Position p, int xrad, int yrad, Color color, bool isSolid);
//TODO void drawDot(CoordinateType::Enum ctype, int x, int y, Color color);
void Game_drawDotMap(Game* self, Position p, Color color);
void Game_drawDotMouse(Game* self, Position p, Color color);
void Game_drawDotScreen(Game* self, Position p, Color color);
// TODO void drawLine(CoordinateType::Enum ctype, int x1, int y1, int x2, int y2, Color color);
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
// TODO    virtual const Regionset &getAllRegions();
Region* Game_getRegionAt(Game* self, Position position);
int Game_getLastEventTime(Game* self);
bool Game_setRevealAll(Game* self, bool reveal);
TilePosition Game_getBuildLocation(Game* self, UnitType type, TilePosition desiredPosition, int maxRange, bool creep);
int Game_getDamageFrom(Game* self, UnitType fromType, UnitType toType, Player* fromPlayer, Player* toPlayer);
int Game_getDamageTo(Game* self, UnitType toType, UnitType fromType, Player* toPlayer, Player* fromPlayer);
unsigned Game_getRandomSeed(Game* self);

#ifdef __cplusplus
} // extern "C"
#endif
