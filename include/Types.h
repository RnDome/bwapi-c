#pragma once

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void* Unit;
typedef void* UnitCommand;
typedef void* Race;
typedef void* Player;
typedef void* Region;
typedef void* Order;
typedef void* Force;
typedef void* Color;


typedef void* UnitType;
typedef void* PlayerType;
typedef void* WeaponType;
typedef void* TechType;
typedef void* UpgradeType;
typedef void* UnitCommandType;

typedef struct { int x; int y; } Position;
typedef struct { int x; int y; } TilePosition;

#ifdef __cplusplus
}
#endif
