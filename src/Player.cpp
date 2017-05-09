#include <Player.h>
#include <BwString.h>
#include <BWAPI/Player.h>
#include <BWAPI/Unitset.h>

#include "Color.hpp"
#include "Position.hpp"
#include "Race.hpp"
#include "PlayerType.hpp"
#include "UnitType.hpp"
#include "TechType.hpp"
#include "UpgradeType.hpp"
#include "WeaponType.hpp"
#include "IteratorImpl.hpp"

namespace BWAPI {
    typedef const PlayerInterface* ConstPlayer;
}

int Player_getID(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->getID();
}

BwString* Player_getName(const Player* self) {
    const std::string& name = safe_cast<BWAPI::ConstPlayer>(self)->getName();
    return BwString_new(name.c_str(), name.length());
}

UnitIterator* Player_getUnits(Player* self) {
    const auto units = reinterpret_cast<BWAPI::Player>(self)->getUnits();
    return into_iter<UnitIterator>(units);
}

Race Player_getRace(Player* self) {
    return race_from_bw( reinterpret_cast<BWAPI::Player>(self)->getRace() );
}

PlayerType Player_getType(Player* self) {
    return playertype_from_bw( reinterpret_cast<BWAPI::Player>(self)->getType() );
}

Force* Player_getForce(Player* self) {
    return reinterpret_cast<Force*>( reinterpret_cast<BWAPI::Player>(self)->getForce() );
}

bool Player_isAlly(Player* self, Player* player) {
    return reinterpret_cast<BWAPI::Player>(self)->isAlly(reinterpret_cast<BWAPI::Player>(player));
}

bool Player_isEnemy(Player* self, Player* player) {
    return reinterpret_cast<BWAPI::Player>(self)->isEnemy(reinterpret_cast<BWAPI::Player>(player));
}

bool Player_isNeutral(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->isNeutral();
}

TilePosition Player_getStartLocation(Player* self) {
    return tileposition_from_bw( reinterpret_cast<BWAPI::Player>(self)->getStartLocation() );
}

bool Player_isVictorious(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->isVictorious();
}

bool Player_isDefeated(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->isDefeated();
}

bool Player_leftGame(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->leftGame();
}

int Player_minerals(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->minerals();
}

int Player_gas(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->gas();
}

int Player_gatheredMinerals(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->gatheredMinerals();
}

int Player_gatheredGas(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->gatheredGas();
}

int Player_repairedMinerals(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->repairedMinerals();
}

int Player_repairedGas(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->repairedGas();
}

int Player_refundedMinerals(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->refundedMinerals();
}

int Player_refundedGas(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->refundedGas();
}

int Player_spentMinerals(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->spentMinerals();
}

int Player_spentGas(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->spentGas();
}

int Player_supplyTotal(Player* self, Race race) {
    return reinterpret_cast<BWAPI::Player>(self)->supplyTotal(race_to_bw(race));
}

int Player_supplyUsed(Player* self, Race race) {
    return reinterpret_cast<BWAPI::Player>(self)->supplyUsed(race_to_bw(race));
}

int Player_allUnitCount(Player* self, UnitType unit) {
    return reinterpret_cast<BWAPI::Player>(self)->allUnitCount(unittype_to_bw(unit));
}

int Player_visibleUnitCount(Player* self, UnitType unit) {
    return reinterpret_cast<BWAPI::Player>(self)->visibleUnitCount(unittype_to_bw(unit));
}

int Player_completedUnitCount(Player* self, UnitType unit) {
    return reinterpret_cast<BWAPI::Player>(self)->completedUnitCount(unittype_to_bw(unit));
}

int Player_incompleteUnitCount(Player* self, UnitType unit) {
    return reinterpret_cast<BWAPI::Player>(self)->incompleteUnitCount(unittype_to_bw(unit));
}

int Player_deadUnitCount(Player* self, UnitType unit) {
    return reinterpret_cast<BWAPI::Player>(self)->deadUnitCount(unittype_to_bw(unit));
}

int Player_killedUnitCount(Player* self, UnitType unit) {
    return reinterpret_cast<BWAPI::Player>(self)->killedUnitCount(unittype_to_bw(unit));
}

int Player_getUpgradeLevel(Player* self, UpgradeType upgrade) {
    return reinterpret_cast<BWAPI::Player>(self)->getUpgradeLevel(upgradetype_to_bw(upgrade));
}

bool Player_hasResearched(Player* self, TechType tech) {
    return reinterpret_cast<BWAPI::Player>(self)->hasResearched(techtype_to_bw(tech));
}

bool Player_isResearching(Player* self, TechType tech) {
    return reinterpret_cast<BWAPI::Player>(self)->isResearching(techtype_to_bw(tech));
}

bool Player_isUpgrading(Player* self, UpgradeType upgrade) {
    return reinterpret_cast<BWAPI::Player>(self)->isUpgrading(upgradetype_to_bw(upgrade));
}

Color Player_getColor(Player* self) {
    return color_from_bw( reinterpret_cast<BWAPI::Player>(self)->getColor() );
}

char Player_getTextColor(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->getTextColor();
}

int Player_maxEnergy(Player* self, UnitType unit) {
    return reinterpret_cast<BWAPI::Player>(self)->maxEnergy(unittype_to_bw(unit));
}

double Player_topSpeed(Player* self, UnitType unit) {
    return reinterpret_cast<BWAPI::Player>(self)->topSpeed(unittype_to_bw(unit));
}

int Player_weaponMaxRange(Player* self, WeaponType weapon) {
    return reinterpret_cast<BWAPI::Player>(self)->weaponMaxRange(weapontype_to_bw(weapon));
}

int Player_sightRange(Player* self, UnitType unit) {
    return reinterpret_cast<BWAPI::Player>(self)->sightRange(unittype_to_bw(unit));
}

int Player_weaponDamageCooldown(Player* self, UnitType unit) {
    return reinterpret_cast<BWAPI::Player>(self)->weaponDamageCooldown(unittype_to_bw(unit));
}

int Player_armor(Player* self, UnitType unit) {
    return reinterpret_cast<BWAPI::Player>(self)->armor(unittype_to_bw(unit));
}

int Player_damage(Player* self, WeaponType wpn) {
    return reinterpret_cast<BWAPI::Player>(self)->damage(weapontype_to_bw(wpn));
}

int Player_getUnitScore(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->getUnitScore();
}

int Player_getKillScore(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->getKillScore();
}

int Player_getBuildingScore(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->getBuildingScore();
}

int Player_getRazingScore(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->getRazingScore();
}

int Player_getCustomScore(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->getCustomScore();
}

bool Player_isObserver(Player* self) {
    return reinterpret_cast<BWAPI::Player>(self)->isObserver();
}

int Player_getMaxUpgradeLevel(Player* self, UpgradeType upgrade) {
    return reinterpret_cast<BWAPI::Player>(self)->getMaxUpgradeLevel(upgradetype_to_bw(upgrade));
}

bool Player_isResearchAvailable(Player* self, TechType tech) {
    return reinterpret_cast<BWAPI::Player>(self)->isResearchAvailable(techtype_to_bw(tech));
}

bool Player_isUnitAvailable(Player* self, UnitType unit) {
    return reinterpret_cast<BWAPI::Player>(self)->isUnitAvailable(unittype_to_bw(unit));
}

bool Player_hasUnitTypeRequirement(Player* self, UnitType unit, int amount) {
    return reinterpret_cast<BWAPI::Player>(self)->hasUnitTypeRequirement(unittype_to_bw(unit), amount);
}
