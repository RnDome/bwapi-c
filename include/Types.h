#pragma once

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/// These are interface-only types with provided API
///  You should use them only by pointer

typedef struct Unit Unit;
typedef struct UnitCommand UnitCommand;
typedef struct Player Player;
typedef struct Region Region;
typedef struct Force Force;
typedef struct Bullet Bullet;

/// These are value-only structs with no API
///  You should implement API on your own

typedef struct Race { int id; } Race;
typedef struct Order { int id; } Order;

typedef struct UnitType { int id; } UnitType;
typedef struct PlayerType { int id; } PlayerType;
typedef struct WeaponType { int id; } WeaponType;
typedef struct TechType { int id; } TechType;
typedef struct UpgradeType { int id; } UpgradeType;
typedef struct UnitCommandType { int id; } UnitCommandType;
typedef struct BulletType { int id; } BulletType;

typedef struct Color { int color; } Color;
typedef struct Position { int x; int y; } Position;
typedef struct TilePosition { int x; int y; } TilePosition;

// Custom type to map getName functions
typedef struct String String;

#ifdef __cplusplus
} // extern "C"
#endif
