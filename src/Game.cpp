#include <Game.h>
#include <BwString.h>
#include <BWAPI/Game.h>
#include <BWAPI/Unitset.h>
#include <BWAPI/Playerset.h>
#include <BWAPI/Forceset.h>
#include <BWAPI/Bulletset.h>
#include <BWAPI/Regionset.h>

#include "GameType.hpp"
#include "UnitType.hpp"
#include "UpgradeType.hpp"
#include "TechType.hpp"
#include "Position.hpp"
#include "Color.hpp"
#include "Input.hpp"
#include "Error.hpp"
#include "CoordinateType.hpp"
#include "IteratorImpl.hpp"

ForceIterator* Game_getForces(Game* self) {
    const auto& forces = reinterpret_cast<BWAPI::Game*>(self)->getForces();
    return as_iter<ForceIterator>(forces);
}

PlayerIterator* Game_getPlayers(Game* self) {
    const auto& players = reinterpret_cast<BWAPI::Game*>(self)->getPlayers();
    return as_iter<PlayerIterator>(players);
}

BulletIterator* Game_getBullets(Game* self) {
    const auto& bullets = reinterpret_cast<BWAPI::Game*>(self)->getBullets();
    return as_iter<BulletIterator>(bullets);
}

UnitIterator* Game_getAllUnits(Game* self) {
    const auto& units = reinterpret_cast<BWAPI::Game*>(self)->getAllUnits();
    return as_iter<UnitIterator>(units);
}

UnitIterator* Game_getMinerals(Game* self) {
    const auto& minerals = reinterpret_cast<BWAPI::Game*>(self)->getMinerals();
    return as_iter<UnitIterator>(minerals);
}

UnitIterator* Game_getGeysers(Game* self) {
    const auto& geysers = reinterpret_cast<BWAPI::Game*>(self)->getGeysers();
    return as_iter<UnitIterator>(geysers);
}

UnitIterator* Game_getNeutralUnits(Game* self) {
    const auto& units = reinterpret_cast<BWAPI::Game*>(self)->getNeutralUnits();
    return as_iter<UnitIterator>(units);
}

UnitIterator* Game_getStaticMinerals(Game* self) {
    const auto& minerals = reinterpret_cast<BWAPI::Game*>(self)->getStaticMinerals();
    return as_iter<UnitIterator>(minerals);
}

UnitIterator* Game_getStaticGeysers(Game* self) {
    const auto& geysers = reinterpret_cast<BWAPI::Game*>(self)->getStaticGeysers();
    return as_iter<UnitIterator>(geysers);
}

UnitIterator* Game_getStaticNeutralUnits(Game* self) {
    const auto& units = reinterpret_cast<BWAPI::Game*>(self)->getStaticNeutralUnits();
    return as_iter<UnitIterator>(units);
}

Force* Game_getForce(Game* self, int forceID) {
    return reinterpret_cast<Force*>( reinterpret_cast<BWAPI::Game*>(self)->getForce(forceID) );
}

Player* Game_getPlayer(Game* self, int playerID) {
    return reinterpret_cast<Player*>( reinterpret_cast<BWAPI::Game*>(self)->getPlayer(playerID) );
}

Unit* Game_getUnit(Game* self, int unitID) {
    return reinterpret_cast<Unit*>( reinterpret_cast<BWAPI::Game*>(self)->getUnit(unitID) );
}

Unit* Game_indexToUnit(Game* self, int unitIndex) {
    return reinterpret_cast<Unit*>( reinterpret_cast<BWAPI::Game*>(self)->indexToUnit(unitIndex) );
}

Region* Game_getRegion(Game* self, int regionID) {
    return reinterpret_cast<Region*>( reinterpret_cast<BWAPI::Game*>(self)->getRegion(regionID) );
}

GameType Game_getGameType(Game* self) {
    return gametype_from_bw( reinterpret_cast<BWAPI::Game*>(self)->getGameType() );
}

int Game_getLatency(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->getLatency();
}

int Game_getFrameCount(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->getFrameCount();
}

int Game_getReplayFrameCount(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->getReplayFrameCount();
}

int Game_getFPS(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->getFPS();
}

double Game_getAverageFPS(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->getAverageFPS();
}

Position Game_getMousePosition(Game* self) {
    return position_from_bw( reinterpret_cast<BWAPI::Game*>(self)->getMousePosition() );
}

bool Game_getMouseState(Game* self, MouseButton button) {
    return reinterpret_cast<BWAPI::Game*>(self)->getMouseState(mousebutton_to_bw(button));
}

bool Game_getKeyState(Game* self, KeyButton key) {
    return reinterpret_cast<BWAPI::Game*>(self)->getKeyState(keybutton_to_bw(key));
}

Position Game_getScreenPosition(Game* self) {
    return position_from_bw( reinterpret_cast<BWAPI::Game*>(self)->getScreenPosition() );
}

void Game_setScreenPosition(Game* self, Position p) {
    reinterpret_cast<BWAPI::Game*>(self)->setScreenPosition(position_to_bw(p));
}

void Game_pingMinimap(Game* self, Position p) {
    reinterpret_cast<BWAPI::Game*>(self)->pingMinimap(position_to_bw(p));
}

bool Game_isFlagEnabled(Game* self, int flag) {
    return reinterpret_cast<BWAPI::Game*>(self)->isFlagEnabled(flag);
}

void Game_enableFlag(Game* self, int flag) {
    reinterpret_cast<BWAPI::Game*>(self)->enableFlag(flag);
}

Error Game_getLastError(Game* self) {
    return error_from_bw( reinterpret_cast<BWAPI::Game*>(self)->getLastError() );
}

bool Game_setLastError(Game* self, Error e) {
    return reinterpret_cast<BWAPI::Game*>(self)->setLastError(error_to_bw(e));
}

int Game_mapWidth(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->mapWidth();
}

int Game_mapHeight(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->mapHeight();
}

BwString* Game_mapFileName(Game* self) {
    const std::string& name = reinterpret_cast<BWAPI::Game*>(self)->mapFileName();
    return BwString_new(name.c_str(), name.length());
}

BwString* Game_mapPathName(Game* self) {
    const std::string& name = reinterpret_cast<BWAPI::Game*>(self)->mapPathName();
    return BwString_new(name.c_str(), name.length());
}

BwString* Game_mapName(Game* self) {
    const std::string& name = reinterpret_cast<BWAPI::Game*>(self)->mapName();
    return BwString_new(name.c_str(), name.length());
}

BwString* Game_mapHash(Game* self) {
    const std::string& hash = reinterpret_cast<BWAPI::Game*>(self)->mapHash();
    return BwString_new(hash.c_str(), hash.length());
}

bool Game_isWalkable(Game* self, WalkPosition position) {
    return reinterpret_cast<BWAPI::Game*>(self)->isWalkable(walkposition_to_bw(position));
}

int Game_getGroundHeight(Game* self, TilePosition position) {
    return reinterpret_cast<BWAPI::Game*>(self)->getGroundHeight(tileposition_to_bw(position));
}

bool Game_isBuildable(Game* self, TilePosition position, bool includeBuildings) {
    return reinterpret_cast<BWAPI::Game*>(self)->isBuildable(tileposition_to_bw(position), includeBuildings);
}

bool Game_isVisible(Game* self, TilePosition position) {
    return reinterpret_cast<BWAPI::Game*>(self)->isVisible(tileposition_to_bw(position));
}

bool Game_isExplored(Game* self, TilePosition position) {
    return reinterpret_cast<BWAPI::Game*>(self)->isExplored(tileposition_to_bw(position));
}

bool Game_hasCreep(Game* self, TilePosition position) {
    return reinterpret_cast<BWAPI::Game*>(self)->hasCreep(tileposition_to_bw(position));
}

bool Game_hasPowerPrecise(Game* self, Position position, UnitType unitType) {
    return reinterpret_cast<BWAPI::Game*>(self)->hasPowerPrecise(position_to_bw(position), unittype_to_bw(unitType));
}

bool Game_hasPower(Game* self, TilePosition position, UnitType unitType) {
    return reinterpret_cast<BWAPI::Game*>(self)->hasPower(tileposition_to_bw(position), unittype_to_bw(unitType));
}

bool Game_hasPowerWH(Game* self, TilePosition position, int tileWidth, int tileHeight, UnitType unitType) {
    return reinterpret_cast<BWAPI::Game*>(self)->hasPower(tileposition_to_bw(position), tileWidth, tileHeight, unittype_to_bw(unitType));
}

bool Game_canBuildHere(Game* self, TilePosition position, UnitType type, Unit* builder, bool checkExplored) {
    return reinterpret_cast<BWAPI::Game*>(self)->canBuildHere(tileposition_to_bw(position), unittype_to_bw(type), reinterpret_cast<BWAPI::Unit>(builder), checkExplored);
}

bool Game_canMake(Game* self, UnitType type, Unit* builder) {
    return reinterpret_cast<BWAPI::Game*>(self)->canMake(unittype_to_bw(type), reinterpret_cast<BWAPI::Unit>(builder));
}

bool Game_canResearch(Game* self, TechType type, Unit* unit, bool checkCanIssueCommandType) {
    return reinterpret_cast<BWAPI::Game*>(self)->canResearch(techtype_to_bw(type), reinterpret_cast<BWAPI::Unit>(unit), checkCanIssueCommandType);
}

bool Game_canUpgrade(Game* self, UpgradeType type, Unit* unit, bool checkCanIssueCommandType) {
    return reinterpret_cast<BWAPI::Game*>(self)->canUpgrade(upgradetype_to_bw(type), reinterpret_cast<BWAPI::Unit>(unit), checkCanIssueCommandType);
}

void Game_printf(Game* self, const char* format, ...) {
    va_list args;
    va_start(args, format);
    Game_vPrintf(self, format, args);
    va_end(args);
}

void Game_vPrintf(Game* self, const char* format, va_list args) {
    reinterpret_cast<BWAPI::Game*>(self)->vPrintf(format, args);
}

void Game_sendText(Game* self, const char* format, ...)
{
    va_list args;
    va_start(args, format);
    Game_vSendText(self, format, args);
    va_end(args);
}

void Game_vSendText(Game* self, const char* format, va_list args) {
    reinterpret_cast<BWAPI::Game*>(self)->vSendText(format, args);
}

void Game_sendTextEx(Game* self, bool toAllies, const char* format, ...) {
    va_list args;
    va_start(args, format);
    Game_vSendTextEx(self, toAllies, format, args);
    va_end(args);
}

void Game_vSendTextEx(Game* self, bool toAllies, const char* format, va_list args) {
    reinterpret_cast<BWAPI::Game*>(self)->vSendTextEx(toAllies, format, args);
}

bool Game_isInGame(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->isInGame();
}

bool Game_isMultiplayer(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->isMultiplayer();
}

bool Game_isBattleNet(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->isBattleNet();
}

bool Game_isPaused(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->isPaused();
}

bool Game_isReplay(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->isReplay();
}

void Game_pauseGame(Game* self) {
    reinterpret_cast<BWAPI::Game*>(self)->pauseGame();
}

void Game_resumeGame(Game* self) {
    reinterpret_cast<BWAPI::Game*>(self)->resumeGame();
}

void Game_leaveGame(Game* self) {
    reinterpret_cast<BWAPI::Game*>(self)->leaveGame();
}

void Game_restartGame(Game* self) {
    reinterpret_cast<BWAPI::Game*>(self)->restartGame();
}

void Game_setLocalSpeed(Game* self, int speed) {
    reinterpret_cast<BWAPI::Game*>(self)->setLocalSpeed(speed);
}

UnitIterator* Game_getSelectedUnits(Game* self) {
    const auto& units = reinterpret_cast<BWAPI::Game*>(self)->getSelectedUnits();
    return as_iter<UnitIterator>(units);
}

Player* Game_self(Game* self) {
    return reinterpret_cast<Player*>( reinterpret_cast<BWAPI::Game*>(self)->self() );
}

Player* Game_enemy(Game* self) {
    return reinterpret_cast<Player*>( reinterpret_cast<BWAPI::Game*>(self)->enemy() );
}

Player* Game_neutral(Game* self) {
    return reinterpret_cast<Player*>( reinterpret_cast<BWAPI::Game*>(self)->neutral() );
}

PlayerIterator* Game_allies(Game* self) {
    const auto& allies = reinterpret_cast<BWAPI::Game*>(self)->allies();
    return as_iter<PlayerIterator>(allies);
}

PlayerIterator* Game_enemies(Game* self) {
    const auto& enemies = reinterpret_cast<BWAPI::Game*>(self)->enemies();
    return as_iter<PlayerIterator>(enemies);
}

PlayerIterator* Game_observers(Game* self) {
    const auto& observers = reinterpret_cast<BWAPI::Game*>(self)->observers();
    return as_iter<PlayerIterator>(observers);
}

void Game_vDrawText(Game* self, CoordinateType ctype, int x, int y, const char* format, va_list args) {
    reinterpret_cast<BWAPI::Game*>(self)->vDrawText(coordinatetype_to_bw(ctype), x, y, format, args);
}

void Game_drawText(Game* self, CoordinateType ctype, int x, int y, const char* format, ...) {
    va_list args;
    va_start(args, format);
    reinterpret_cast<BWAPI::Game*>(self)->vDrawText(coordinatetype_to_bw(ctype), x, y, format, args);
    va_end(args);
}

void Game_drawTextMap(Game* self, Position p, const char* format, ...) {
    va_list args;
    va_start(args, format);
    reinterpret_cast<BWAPI::Game*>(self)->vDrawText(BWAPI::CoordinateType::Map, p.x, p.y, format, args);
    va_end(args);
}

void Game_drawTextMouse(Game* self, Position p, const char* format, ...) {
    va_list args;
    va_start(args, format);
    reinterpret_cast<BWAPI::Game*>(self)->vDrawText(BWAPI::CoordinateType::Mouse, p.x, p.y, format, args);
    va_end(args);
}

void Game_drawTextScreen(Game* self, Position p, const char* format, ...) {
    va_list args;
    va_start(args, format);
    reinterpret_cast<BWAPI::Game*>(self)->vDrawText(BWAPI::CoordinateType::Screen, p.x, p.y, format, args);
    va_end(args);
}

void Game_drawBox(Game* self, CoordinateType ctype, int left, int top, int right, int bottom, Color color, bool isSolid) {
    reinterpret_cast<BWAPI::Game*>(self)->drawBox(coordinatetype_to_bw(ctype), left, top, right, bottom, color_to_bw(color), isSolid);
}

void Game_drawBoxMap(Game* self, Position leftTop, Position rightBottom, Color color, bool isSolid) {
    return reinterpret_cast<BWAPI::Game*>(self)->drawBoxMap(position_to_bw(leftTop), position_to_bw(rightBottom), color_to_bw(color), isSolid);
}

void Game_drawBoxMouse(Game* self, Position leftTop, Position rightBottom, Color color, bool isSolid) {
    return reinterpret_cast<BWAPI::Game*>(self)->drawBoxMouse(position_to_bw(leftTop), position_to_bw(rightBottom), color_to_bw(color), isSolid);
}

void Game_drawBoxScreen(Game* self, Position leftTop, Position rightBottom, Color color, bool isSolid) {
    reinterpret_cast<BWAPI::Game*>(self)->drawBoxScreen(position_to_bw(leftTop), position_to_bw(rightBottom), color_to_bw(color), isSolid);
}

void Game_drawTriangle(Game* self, CoordinateType ctype, int ax, int ay, int bx, int by, int cx, int cy, Color color, bool isSolid) {
    reinterpret_cast<BWAPI::Game*>(self)->drawTriangle(coordinatetype_to_bw(ctype), ax, ay, bx, by, cx, cy, color_to_bw(color), isSolid);
}

void Game_drawTriangleMap(Game* self, Position a, Position b, Position c, Color color, bool isSolid) {
    reinterpret_cast<BWAPI::Game*>(self)->drawTriangleMap(position_to_bw(a), position_to_bw(b), position_to_bw(c), color_to_bw(color), isSolid);
}

void Game_drawTriangleMouse(Game* self, Position a, Position b, Position c, Color color, bool isSolid) {
    reinterpret_cast<BWAPI::Game*>(self)->drawTriangleMouse(position_to_bw(a), position_to_bw(b), position_to_bw(c), color_to_bw(color), isSolid);
}

void Game_drawTriangleScreen(Game* self, Position a, Position b, Position c, Color color, bool isSolid) {
    reinterpret_cast<BWAPI::Game*>(self)->drawTriangleScreen(position_to_bw(a), position_to_bw(b), position_to_bw(c), color_to_bw(color), isSolid);
}

void Game_drawCircle(Game* self, CoordinateType ctype, int x, int y, int radius, Color color, bool isSolid) {
    reinterpret_cast<BWAPI::Game*>(self)->drawCircle(coordinatetype_to_bw(ctype), x, y, radius, color_to_bw(color), isSolid);
}

void Game_drawCircleMap(Game* self, Position p, int radius, Color color, bool isSolid) {
    return reinterpret_cast<BWAPI::Game*>(self)->drawCircleMap(position_to_bw(p), radius, color_to_bw(color), isSolid);
}

void Game_drawCircleMouse(Game* self, Position p, int radius, Color color, bool isSolid) {
    return reinterpret_cast<BWAPI::Game*>(self)->drawCircleMouse(position_to_bw(p), radius, color_to_bw(color), isSolid);
}

void Game_drawCircleScreen(Game* self, Position p, int radius, Color color, bool isSolid) {
    return reinterpret_cast<BWAPI::Game*>(self)->drawCircleScreen(position_to_bw(p), radius, color_to_bw(color), isSolid);
}

void Game_drawEllipse(Game* self, CoordinateType ctype, int x, int y, int xrad, int yrad, Color color, bool isSolid) {
    reinterpret_cast<BWAPI::Game*>(self)->drawEllipse(coordinatetype_to_bw(ctype), x, y, xrad, yrad, color_to_bw(color), isSolid);
}

void Game_drawEllipseMap(Game* self, Position p, int xrad, int yrad, Color color, bool isSolid) {
    return reinterpret_cast<BWAPI::Game*>(self)->drawEllipseMap(position_to_bw(p), xrad, yrad, color_to_bw(color), isSolid);
}

void Game_drawEllipseMouse(Game* self, Position p, int xrad, int yrad, Color color, bool isSolid) {
    reinterpret_cast<BWAPI::Game*>(self)->drawEllipseMouse(position_to_bw(p), xrad, yrad, color_to_bw(color), isSolid);
}

void Game_drawEllipseScreen(Game* self, Position p, int xrad, int yrad, Color color, bool isSolid) {
    reinterpret_cast<BWAPI::Game*>(self)->drawEllipseScreen(position_to_bw(p), xrad, yrad, color_to_bw(color), isSolid);
}

void Game_drawDot(Game* self, CoordinateType ctype, int x, int y, Color color) {
    reinterpret_cast<BWAPI::Game*>(self)->drawDot(coordinatetype_to_bw(ctype), x, y, color_to_bw(color));
}

void Game_drawDotMap(Game* self, Position p, Color color) {
    reinterpret_cast<BWAPI::Game*>(self)->drawDotMap(position_to_bw(p), color_to_bw(color));
}

void Game_drawDotMouse(Game* self, Position p, Color color) {
    reinterpret_cast<BWAPI::Game*>(self)->drawDotMouse(position_to_bw(p), color_to_bw(color));
}

void Game_drawDotScreen(Game* self, Position p, Color color) {
    reinterpret_cast<BWAPI::Game*>(self)->drawDotScreen(position_to_bw(p), color_to_bw(color));
}

void Game_drawLine(Game* self, CoordinateType ctype, int x1, int y1, int x2, int y2, Color color) {
    reinterpret_cast<BWAPI::Game*>(self)->drawLine(coordinatetype_to_bw(ctype), x1, y1, x2, y2, color_to_bw(color));
}

void Game_drawLineMap(Game* self, Position a, Position b, Color color) {
    reinterpret_cast<BWAPI::Game*>(self)->drawLineMap(position_to_bw(a), position_to_bw(b), color_to_bw(color));
}

void Game_drawLineMouse(Game* self, Position a, Position b, Color color) {
    reinterpret_cast<BWAPI::Game*>(self)->drawLineMouse(position_to_bw(a), position_to_bw(b), color_to_bw(color));
}

void Game_drawLineScreen(Game* self, Position a, Position b, Color color) {
    reinterpret_cast<BWAPI::Game*>(self)->drawLineScreen(position_to_bw(a), position_to_bw(b), color_to_bw(color));
}

int Game_getLatencyFrames(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->getLatencyFrames();
}

int Game_getLatencyTime(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->getLatencyTime();
}

int Game_getRemainingLatencyFrames(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->getRemainingLatencyFrames();
}

int Game_getRemainingLatencyTime(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->getRemainingLatencyTime();
}

int Game_getRevision(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->getRevision();
}

int Game_getClientVersion(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->getClientVersion();
}

bool Game_isDebug(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->isDebug();
}

bool Game_isLatComEnabled(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->isLatComEnabled();
}

void Game_setLatCom(Game* self, bool isEnabled) {
    reinterpret_cast<BWAPI::Game*>(self)->setLatCom(isEnabled);
}

bool Game_isGUIEnabled(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->isGUIEnabled();
}

void Game_setGUI(Game* self, bool enabled) {
    reinterpret_cast<BWAPI::Game*>(self)->setGUI(enabled);
}

int Game_getInstanceNumber(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->getInstanceNumber();
}

int Game_getAPM(Game* self, bool includeSelects) {
    return reinterpret_cast<BWAPI::Game*>(self)->getAPM(includeSelects);
}

bool Game_setMap(Game* self, const char* mapFileName) {
    return reinterpret_cast<BWAPI::Game*>(self)->setMap(mapFileName);
}

void Game_setFrameSkip(Game* self, int frameSkip) {
    reinterpret_cast<BWAPI::Game*>(self)->setFrameSkip(frameSkip);
}

bool Game_hasPath(Game* self, Position source, Position destination) {
    return reinterpret_cast<BWAPI::Game*>(self)->hasPath(position_to_bw(source), position_to_bw(destination));
}

bool Game_setAlliance(Game* self, Player* player, bool allied, bool alliedVictory) {
    return reinterpret_cast<BWAPI::Game*>(self)->setAlliance(reinterpret_cast<BWAPI::Player>(player), allied, alliedVictory);
}

bool Game_setVision(Game* self, Player* player, bool enabled) {
    return reinterpret_cast<BWAPI::Game*>(self)->setVision(reinterpret_cast<BWAPI::Player>(player), enabled);
}

int Game_elapsedTime(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->elapsedTime();
}

void Game_setCommandOptimizationLevel(Game* self, int level) {
    return reinterpret_cast<BWAPI::Game*>(self)->setCommandOptimizationLevel(level);
}

int Game_countdownTimer(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->countdownTimer();
}

RegionIterator* Game_getAllRegions(Game* self) {
    const auto& regions = reinterpret_cast<BWAPI::Game*>(self)->getAllRegions();
    return as_iter<RegionIterator>(regions);
}

Region* Game_getRegionAt(Game* self, Position position) {
    return reinterpret_cast<Region*>( reinterpret_cast<BWAPI::Game*>(self)->getRegionAt(position_to_bw(position)) );
}

int Game_getLastEventTime(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->getLastEventTime();
}

bool Game_setRevealAll(Game* self, bool reveal) {
    return reinterpret_cast<BWAPI::Game*>(self)->setRevealAll(reveal);
}

TilePosition Game_getBuildLocation(Game* self, UnitType type, TilePosition desiredPosition, int maxRange, bool creep) {
    return tileposition_from_bw( reinterpret_cast<BWAPI::Game*>(self)->getBuildLocation(unittype_to_bw(type), tileposition_to_bw(desiredPosition), maxRange, creep) );
}

int Game_getDamageFrom(Game* self, UnitType fromType, UnitType toType, Player* fromPlayer, Player* toPlayer) {
    return reinterpret_cast<BWAPI::Game*>(self)->getDamageFrom(unittype_to_bw(fromType), unittype_to_bw(toType), reinterpret_cast<BWAPI::Player>(fromPlayer), reinterpret_cast<BWAPI::Player>(toPlayer));
}

int Game_getDamageTo(Game* self, UnitType toType, UnitType fromType, Player* toPlayer, Player* fromPlayer) {
    return reinterpret_cast<BWAPI::Game*>(self)->getDamageTo(unittype_to_bw(toType), unittype_to_bw(fromType), reinterpret_cast<BWAPI::Player>(toPlayer), reinterpret_cast<BWAPI::Player>(fromPlayer));
}

unsigned Game_getRandomSeed(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->getRandomSeed();
}
