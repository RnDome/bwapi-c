#include <Game.h>
#include <BwString.h>

#include "IteratorImpl.hpp"

void BWAPIC_setGame(Game* game) {
    BWAPI::BroodwarPtr = reinterpret_cast<BWAPI::Game*>(game);
}

Game* BWAPIC_getGame() {
    return reinterpret_cast<Game*>(BWAPI::BroodwarPtr);
}

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

PositionIterator* Game_getNukeDots(Game* self) {
    const auto& dots = reinterpret_cast<BWAPI::Game*>(self)->getNukeDots();
    return as_value_iter<PositionIterator>(dots);
}

EventIterator* Game_getEvents(Game* self) {
    const auto& events = reinterpret_cast<BWAPI::Game*>(self)->getEvents();
    return as_value_iter<EventIterator>(events);
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
    return cast_from_bw( reinterpret_cast<BWAPI::Game*>(self)->getGameType() );
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
    return cast_from_bw( reinterpret_cast<BWAPI::Game*>(self)->getMousePosition() );
}

bool Game_getMouseState(Game* self, MouseButton button) {
    return reinterpret_cast<BWAPI::Game*>(self)->getMouseState(cast_to_bw(button));
}

bool Game_getKeyState(Game* self, KeyButton key) {
    return reinterpret_cast<BWAPI::Game*>(self)->getKeyState(cast_to_bw(key));
}

Position Game_getScreenPosition(Game* self) {
    return cast_from_bw( reinterpret_cast<BWAPI::Game*>(self)->getScreenPosition() );
}

void Game_setScreenPosition(Game* self, Position p) {
    reinterpret_cast<BWAPI::Game*>(self)->setScreenPosition(cast_to_bw(p));
}

void Game_pingMinimap(Game* self, Position p) {
    reinterpret_cast<BWAPI::Game*>(self)->pingMinimap(cast_to_bw(p));
}

bool Game_isFlagEnabled(Game* self, int flag) {
    return reinterpret_cast<BWAPI::Game*>(self)->isFlagEnabled(flag);
}

void Game_enableFlag(Game* self, int flag) {
    reinterpret_cast<BWAPI::Game*>(self)->enableFlag(flag);
}

UnitIterator* Game_getUnitsOnTile(Game* self, TilePosition tile, UnaryUnitFilter pred) {
    auto pred_filter = reinterpret_cast<bool (*)(BWAPI::Unit)>(pred);
    auto&& units = reinterpret_cast<BWAPI::Game*>(self)->getUnitsOnTile(cast_to_bw(tile), pred_filter);
    return into_iter<UnitIterator>(std::move(units));
}

UnitIterator* Game_getUnitsInRectangle(Game* self, Position topLeft, Position bottomRight, UnaryUnitFilter pred) {
    auto pred_filter = reinterpret_cast<bool (*)(BWAPI::Unit)>(pred);
    auto&& units = reinterpret_cast<BWAPI::Game*>(self)->getUnitsInRectangle(cast_to_bw(topLeft), cast_to_bw(bottomRight), pred_filter);
    return into_iter<UnitIterator>(std::move(units));
}

UnitIterator* Game_getUnitsInRadius(Game* self, Position center, int radius, UnaryUnitFilter pred) {
    auto pred_filter = reinterpret_cast<bool (*)(BWAPI::Unit)>(pred);
    auto&& units = reinterpret_cast<BWAPI::Game*>(self)->getUnitsInRadius(cast_to_bw(center), radius, pred_filter);
    return into_iter<UnitIterator>(std::move(units));
}

Unit* Game_getClosestUnit(Game* self, Position center, UnaryUnitFilter pred, int radius) {
    auto pred_filter = reinterpret_cast<bool (*)(BWAPI::Unit)>(pred);
    auto unit = reinterpret_cast<BWAPI::Game*>(self)->getClosestUnit(cast_to_bw(center), pred_filter, radius);
    return reinterpret_cast<Unit*>(unit);
}

Unit* Game_getClosestUnitInRectangle(Game* self, Position center, UnaryUnitFilter pred, int left, int top, int right, int bottom) {
    auto pred_filter = reinterpret_cast<bool (*)(BWAPI::Unit)>(pred);
    auto unit = reinterpret_cast<BWAPI::Game*>(self)->getClosestUnitInRectangle(cast_to_bw(center), pred_filter, left, top, right, bottom);
    return reinterpret_cast<Unit*>(unit);
}

Unit* Game_getBestUnit(Game* self, BestUnitFilter best, UnaryUnitFilter pred, Position center, int radius) {
    auto best_filter = reinterpret_cast<BWAPI::Unit (*)(BWAPI::Unit, BWAPI::Unit)>(best);
    auto pred_filter = reinterpret_cast<bool (*)(BWAPI::Unit)>(pred);
    auto unit = reinterpret_cast<BWAPI::Game*>(self)->getBestUnit(best_filter, pred_filter, cast_to_bw(center), radius);
    return reinterpret_cast<Unit*>(unit);
}

Error Game_getLastError(Game* self) {
    return cast_from_bw( reinterpret_cast<BWAPI::Game*>(self)->getLastError() );
}

bool Game_setLastError(Game* self, Error e) {
    return reinterpret_cast<BWAPI::Game*>(self)->setLastError(cast_to_bw(e));
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
    return reinterpret_cast<BWAPI::Game*>(self)->isWalkable(cast_to_bw(position));
}

int Game_getGroundHeight(Game* self, TilePosition position) {
    return reinterpret_cast<BWAPI::Game*>(self)->getGroundHeight(cast_to_bw(position));
}

bool Game_isBuildable(Game* self, TilePosition position, bool includeBuildings) {
    return reinterpret_cast<BWAPI::Game*>(self)->isBuildable(cast_to_bw(position), includeBuildings);
}

bool Game_isVisible(Game* self, TilePosition position) {
    return reinterpret_cast<BWAPI::Game*>(self)->isVisible(cast_to_bw(position));
}

bool Game_isExplored(Game* self, TilePosition position) {
    return reinterpret_cast<BWAPI::Game*>(self)->isExplored(cast_to_bw(position));
}

bool Game_hasCreep(Game* self, TilePosition position) {
    return reinterpret_cast<BWAPI::Game*>(self)->hasCreep(cast_to_bw(position));
}

bool Game_hasPowerPrecise(Game* self, Position position, UnitType unitType) {
    return reinterpret_cast<BWAPI::Game*>(self)->hasPowerPrecise(cast_to_bw(position), cast_to_bw(unitType));
}

bool Game_hasPower(Game* self, TilePosition position, UnitType unitType) {
    return reinterpret_cast<BWAPI::Game*>(self)->hasPower(cast_to_bw(position), cast_to_bw(unitType));
}

bool Game_hasPowerWH(Game* self, TilePosition position, int tileWidth, int tileHeight, UnitType unitType) {
    return reinterpret_cast<BWAPI::Game*>(self)->hasPower(cast_to_bw(position), tileWidth, tileHeight, cast_to_bw(unitType));
}

bool Game_canBuildHere(Game* self, TilePosition position, UnitType type, Unit* builder, bool checkExplored) {
    return reinterpret_cast<BWAPI::Game*>(self)->canBuildHere(cast_to_bw(position), cast_to_bw(type), reinterpret_cast<BWAPI::Unit>(builder), checkExplored);
}

bool Game_canMake(Game* self, UnitType type, Unit* builder) {
    return reinterpret_cast<BWAPI::Game*>(self)->canMake(cast_to_bw(type), reinterpret_cast<BWAPI::Unit>(builder));
}

bool Game_canResearch(Game* self, TechType type, Unit* unit, bool checkCanIssueCommandType) {
    return reinterpret_cast<BWAPI::Game*>(self)->canResearch(cast_to_bw(type), reinterpret_cast<BWAPI::Unit>(unit), checkCanIssueCommandType);
}

bool Game_canUpgrade(Game* self, UpgradeType type, Unit* unit, bool checkCanIssueCommandType) {
    return reinterpret_cast<BWAPI::Game*>(self)->canUpgrade(cast_to_bw(type), reinterpret_cast<BWAPI::Unit>(unit), checkCanIssueCommandType);
}

TilePositionIterator* Game_getStartLocations(Game* self) {
    const auto& tiles = reinterpret_cast<BWAPI::Game*>(self)->getStartLocations();
    return as_value_iter<TilePositionIterator>(tiles);
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
    reinterpret_cast<BWAPI::Game*>(self)->vDrawText(cast_to_bw(ctype), x, y, format, args);
}

void Game_drawText(Game* self, CoordinateType ctype, int x, int y, const char* format, ...) {
    va_list args;
    va_start(args, format);
    reinterpret_cast<BWAPI::Game*>(self)->vDrawText(cast_to_bw(ctype), x, y, format, args);
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
    reinterpret_cast<BWAPI::Game*>(self)->drawBox(cast_to_bw(ctype), left, top, right, bottom, cast_to_bw(color), isSolid);
}

void Game_drawBoxMap(Game* self, Position leftTop, Position rightBottom, Color color, bool isSolid) {
    return reinterpret_cast<BWAPI::Game*>(self)->drawBoxMap(cast_to_bw(leftTop), cast_to_bw(rightBottom), cast_to_bw(color), isSolid);
}

void Game_drawBoxMouse(Game* self, Position leftTop, Position rightBottom, Color color, bool isSolid) {
    return reinterpret_cast<BWAPI::Game*>(self)->drawBoxMouse(cast_to_bw(leftTop), cast_to_bw(rightBottom), cast_to_bw(color), isSolid);
}

void Game_drawBoxScreen(Game* self, Position leftTop, Position rightBottom, Color color, bool isSolid) {
    reinterpret_cast<BWAPI::Game*>(self)->drawBoxScreen(cast_to_bw(leftTop), cast_to_bw(rightBottom), cast_to_bw(color), isSolid);
}

void Game_drawTriangle(Game* self, CoordinateType ctype, int ax, int ay, int bx, int by, int cx, int cy, Color color, bool isSolid) {
    reinterpret_cast<BWAPI::Game*>(self)->drawTriangle(cast_to_bw(ctype), ax, ay, bx, by, cx, cy, cast_to_bw(color), isSolid);
}

void Game_drawTriangleMap(Game* self, Position a, Position b, Position c, Color color, bool isSolid) {
    reinterpret_cast<BWAPI::Game*>(self)->drawTriangleMap(cast_to_bw(a), cast_to_bw(b), cast_to_bw(c), cast_to_bw(color), isSolid);
}

void Game_drawTriangleMouse(Game* self, Position a, Position b, Position c, Color color, bool isSolid) {
    reinterpret_cast<BWAPI::Game*>(self)->drawTriangleMouse(cast_to_bw(a), cast_to_bw(b), cast_to_bw(c), cast_to_bw(color), isSolid);
}

void Game_drawTriangleScreen(Game* self, Position a, Position b, Position c, Color color, bool isSolid) {
    reinterpret_cast<BWAPI::Game*>(self)->drawTriangleScreen(cast_to_bw(a), cast_to_bw(b), cast_to_bw(c), cast_to_bw(color), isSolid);
}

void Game_drawCircle(Game* self, CoordinateType ctype, int x, int y, int radius, Color color, bool isSolid) {
    reinterpret_cast<BWAPI::Game*>(self)->drawCircle(cast_to_bw(ctype), x, y, radius, cast_to_bw(color), isSolid);
}

void Game_drawCircleMap(Game* self, Position p, int radius, Color color, bool isSolid) {
    return reinterpret_cast<BWAPI::Game*>(self)->drawCircleMap(cast_to_bw(p), radius, cast_to_bw(color), isSolid);
}

void Game_drawCircleMouse(Game* self, Position p, int radius, Color color, bool isSolid) {
    return reinterpret_cast<BWAPI::Game*>(self)->drawCircleMouse(cast_to_bw(p), radius, cast_to_bw(color), isSolid);
}

void Game_drawCircleScreen(Game* self, Position p, int radius, Color color, bool isSolid) {
    return reinterpret_cast<BWAPI::Game*>(self)->drawCircleScreen(cast_to_bw(p), radius, cast_to_bw(color), isSolid);
}

void Game_drawEllipse(Game* self, CoordinateType ctype, int x, int y, int xrad, int yrad, Color color, bool isSolid) {
    reinterpret_cast<BWAPI::Game*>(self)->drawEllipse(cast_to_bw(ctype), x, y, xrad, yrad, cast_to_bw(color), isSolid);
}

void Game_drawEllipseMap(Game* self, Position p, int xrad, int yrad, Color color, bool isSolid) {
    return reinterpret_cast<BWAPI::Game*>(self)->drawEllipseMap(cast_to_bw(p), xrad, yrad, cast_to_bw(color), isSolid);
}

void Game_drawEllipseMouse(Game* self, Position p, int xrad, int yrad, Color color, bool isSolid) {
    reinterpret_cast<BWAPI::Game*>(self)->drawEllipseMouse(cast_to_bw(p), xrad, yrad, cast_to_bw(color), isSolid);
}

void Game_drawEllipseScreen(Game* self, Position p, int xrad, int yrad, Color color, bool isSolid) {
    reinterpret_cast<BWAPI::Game*>(self)->drawEllipseScreen(cast_to_bw(p), xrad, yrad, cast_to_bw(color), isSolid);
}

void Game_drawDot(Game* self, CoordinateType ctype, int x, int y, Color color) {
    reinterpret_cast<BWAPI::Game*>(self)->drawDot(cast_to_bw(ctype), x, y, cast_to_bw(color));
}

void Game_drawDotMap(Game* self, Position p, Color color) {
    reinterpret_cast<BWAPI::Game*>(self)->drawDotMap(cast_to_bw(p), cast_to_bw(color));
}

void Game_drawDotMouse(Game* self, Position p, Color color) {
    reinterpret_cast<BWAPI::Game*>(self)->drawDotMouse(cast_to_bw(p), cast_to_bw(color));
}

void Game_drawDotScreen(Game* self, Position p, Color color) {
    reinterpret_cast<BWAPI::Game*>(self)->drawDotScreen(cast_to_bw(p), cast_to_bw(color));
}

void Game_drawLine(Game* self, CoordinateType ctype, int x1, int y1, int x2, int y2, Color color) {
    reinterpret_cast<BWAPI::Game*>(self)->drawLine(cast_to_bw(ctype), x1, y1, x2, y2, cast_to_bw(color));
}

void Game_drawLineMap(Game* self, Position a, Position b, Color color) {
    reinterpret_cast<BWAPI::Game*>(self)->drawLineMap(cast_to_bw(a), cast_to_bw(b), cast_to_bw(color));
}

void Game_drawLineMouse(Game* self, Position a, Position b, Color color) {
    reinterpret_cast<BWAPI::Game*>(self)->drawLineMouse(cast_to_bw(a), cast_to_bw(b), cast_to_bw(color));
}

void Game_drawLineScreen(Game* self, Position a, Position b, Color color) {
    reinterpret_cast<BWAPI::Game*>(self)->drawLineScreen(cast_to_bw(a), cast_to_bw(b), cast_to_bw(color));
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
    return reinterpret_cast<BWAPI::Game*>(self)->hasPath(cast_to_bw(source), cast_to_bw(destination));
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
    return reinterpret_cast<Region*>( reinterpret_cast<BWAPI::Game*>(self)->getRegionAt(cast_to_bw(position)) );
}

int Game_getLastEventTime(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->getLastEventTime();
}

bool Game_setRevealAll(Game* self, bool reveal) {
    return reinterpret_cast<BWAPI::Game*>(self)->setRevealAll(reveal);
}

TilePosition Game_getBuildLocation(Game* self, UnitType type, TilePosition desiredPosition, int maxRange, bool creep) {
    return cast_from_bw( reinterpret_cast<BWAPI::Game*>(self)->getBuildLocation(cast_to_bw(type), cast_to_bw(desiredPosition), maxRange, creep) );
}

int Game_getDamageFrom(Game* self, UnitType fromType, UnitType toType, Player* fromPlayer, Player* toPlayer) {
    return reinterpret_cast<BWAPI::Game*>(self)->getDamageFrom(cast_to_bw(fromType), cast_to_bw(toType), reinterpret_cast<BWAPI::Player>(fromPlayer), reinterpret_cast<BWAPI::Player>(toPlayer));
}

int Game_getDamageTo(Game* self, UnitType toType, UnitType fromType, Player* toPlayer, Player* fromPlayer) {
    return reinterpret_cast<BWAPI::Game*>(self)->getDamageTo(cast_to_bw(toType), cast_to_bw(fromType), reinterpret_cast<BWAPI::Player>(toPlayer), reinterpret_cast<BWAPI::Player>(fromPlayer));
}

unsigned Game_getRandomSeed(Game* self) {
    return reinterpret_cast<BWAPI::Game*>(self)->getRandomSeed();
}
