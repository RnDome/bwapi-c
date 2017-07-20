#pragma once

#include <Types.h>

#ifdef __cplusplus
extern "C" {
#endif

int Player_getID(Player* self);
BwString* Player_getName(Player* self);
UnitIterator* Player_getUnits(Player* self);
Race Player_getRace(Player* self);
PlayerType Player_getType(Player* self);
Force* Player_getForce(Player* self);
bool Player_isAlly(Player* self, Player* player);
bool Player_isEnemy(Player* self, Player* player);
bool Player_isNeutral(Player* self);
TilePosition Player_getStartLocation(Player* self);
bool Player_isVictorious(Player* self);
bool Player_isDefeated(Player* self);
bool Player_leftGame(Player* self);
int Player_minerals(Player* self);
int Player_gas(Player* self);
int Player_gatheredMinerals(Player* self);
int Player_gatheredGas(Player* self);
int Player_repairedMinerals(Player* self);
int Player_repairedGas(Player* self);
int Player_refundedMinerals(Player* self);
int Player_refundedGas(Player* self);
int Player_spentMinerals(Player* self);
int Player_spentGas(Player* self);
int Player_supplyTotal(Player* self, Race race);
int Player_supplyUsed(Player* self, Race race);
int Player_allUnitCount(Player* self, UnitType unit);
int Player_visibleUnitCount(Player* self, UnitType unit);
int Player_completedUnitCount(Player* self, UnitType unit);
int Player_incompleteUnitCount(Player* self, UnitType unit);
int Player_deadUnitCount(Player* self, UnitType unit);
int Player_killedUnitCount(Player* self, UnitType unit);
int Player_getUpgradeLevel(Player* self, UpgradeType upgrade);
bool Player_hasResearched(Player* self, TechType tech);
bool Player_isResearching(Player* self, TechType tech);
bool Player_isUpgrading(Player* self, UpgradeType upgrade);
Color Player_getColor(Player* self);
char Player_getTextColor(Player* self);
int Player_maxEnergy(Player* self, UnitType unit);
double Player_topSpeed(Player* self, UnitType unit);
int Player_weaponMaxRange(Player* self, WeaponType weapon);
int Player_sightRange(Player* self, UnitType unit);
int Player_weaponDamageCooldown(Player* self, UnitType unit);
int Player_armor(Player* self, UnitType unit);
int Player_damage(Player* self, WeaponType wpn);
int Player_getUnitScore(Player* self);
int Player_getKillScore(Player* self);
int Player_getBuildingScore(Player* self);
int Player_getRazingScore(Player* self);
int Player_getCustomScore(Player* self);
bool Player_isObserver(Player* self);
int Player_getMaxUpgradeLevel(Player* self, UpgradeType upgrade);
bool Player_isResearchAvailable(Player* self, TechType tech);
bool Player_isUnitAvailable(Player* self, UnitType unit);
bool Player_hasUnitTypeRequirement(Player* self, UnitType unit, int amount);
void Player_registerEvent(Player* self, void (*const action)(Player*), bool (*const condition)(Player*), int timesToRun, int framesToCheck);

#ifdef __cplusplus
} // extern "C"
#endif
