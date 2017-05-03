#pragma once

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void* Unit;
typedef void* UnitCommand;

typedef void* Player;
typedef void* Region;
typedef void* Order;

typedef void* UnitType;
typedef void* TechType;
typedef void* UpgradeType;
typedef void* UnitCommandType;

typedef struct { int x; int y; } Position;
typedef struct { int x; int y; } TilePosition;

#ifdef __cplusplus
}
#endif
