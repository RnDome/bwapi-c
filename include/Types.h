#pragma once

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/// These are interface-only types with provided API
///  You should use them only by pointer

typedef struct Unit_ Unit;
typedef struct Player_ Player;
typedef struct Region_ Region;
typedef struct Force_ Force;
typedef struct Bullet_ Bullet;
typedef struct Game_ Game;

/// These are value-only structs with no API
///  You should implement API on your own

typedef struct Race { int id; } Race;
typedef struct Order { int id; } Order;
typedef struct Color { int color; } Color;
typedef struct CoordinateType { int id; } CoordinateType;

typedef struct MouseButton { int id; } MouseButton;
typedef struct KeyButton { int id; } KeyButton;
typedef struct Error { int id; } Error;

typedef struct UnitType { int id; } UnitType;
typedef struct PlayerType { int id; } PlayerType;
typedef struct WeaponType { int id; } WeaponType;
typedef struct TechType { int id; } TechType;
typedef struct UpgradeType { int id; } UpgradeType;
typedef struct UnitCommandType { int id; } UnitCommandType;
typedef struct BulletType { int id; } BulletType;
typedef struct GameType { int id; } GameType;

typedef struct Position { int x; int y; } Position;
typedef struct TilePosition { int x; int y; } TilePosition;
typedef struct WalkPosition { int x; int y; } WalkPosition;

typedef struct UnitCommand {
    Unit* unit;
    UnitCommandType type;
    Unit* target;
    int x;
    int y;
    int extra;
} UnitCommand;

// Custom type to map functions returning std::string
typedef struct BwString_ BwString;

// Custom type to map functions returning BWAPI::Unitset...
typedef struct Iterator_ Iterator;
typedef struct UnitIterator_ UnitIterator;
typedef struct PlayerIterator_ PlayerIterator;
typedef struct ForceIterator_ ForceIterator;
typedef struct BulletIterator_ BulletIterator;
typedef struct RegionIterator_ RegionIterator;

#ifdef __cplusplus
} // extern "C"
#endif
