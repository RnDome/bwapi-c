#include <Unit.h>
#include <BWAPI/Unit.h>
#include <BWAPI/Unitset.h>

#include "Position.hpp"
#include "Order.hpp"
#include "TechType.hpp"
#include "UpgradeType.hpp"
#include "WeaponType.hpp"
#include "UnitType.hpp"
#include "UnitCommand.hpp"
#include "IteratorImpl.hpp"

int Unit_getID(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getID();
}

bool Unit_exists(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->exists();
}

int Unit_getReplayID(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getReplayID();
}

Player* Unit_getPlayer(Unit* self) {
    return reinterpret_cast<Player*>( reinterpret_cast<BWAPI::Unit>(self)->getPlayer() );
}

UnitType Unit_getType(Unit* self) {
    return unittype_from_bw( reinterpret_cast<BWAPI::Unit>(self)->getType() );
}

Position Unit_getPosition(Unit* self) {
    return position_from_bw( reinterpret_cast<BWAPI::Unit>(self)->getPosition() );
}

TilePosition Unit_getTilePosition(Unit* self) {
    return tileposition_from_bw( reinterpret_cast<BWAPI::Unit>(self)->getTilePosition() );
}

double Unit_getAngle(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getAngle();
}

double Unit_getVelocityX(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getVelocityX();
}

double Unit_getVelocityY(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getVelocityY();
}

Region* Unit_getRegion(Unit* self) {
    return reinterpret_cast<Region*>( reinterpret_cast<BWAPI::Unit>(self)->getRegion() );
}

int Unit_getLeft(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getLeft();
}

int Unit_getTop(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getTop();
}

int Unit_getRight(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getRight();
}

int Unit_getBottom(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getBottom();
}

int Unit_getHitPoints(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getHitPoints();
}

int Unit_getShields(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getShields();
}

int Unit_getEnergy(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getEnergy();
}

int Unit_getResources(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getResources();
}

int Unit_getResourceGroup(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getResourceGroup();
}

int Unit_getDistance_Position(Unit* self, Position target) {
    return reinterpret_cast<BWAPI::Unit>(self)->getDistance(position_to_bw(target));
}

int Unit_getDistance_Unit(Unit* self, Unit* target) {
    return reinterpret_cast<BWAPI::Unit>(self)->getDistance(reinterpret_cast<BWAPI::Unit>(target));
}

bool Unit_hasPath_Position(Unit* self, Position target) {
    return reinterpret_cast<BWAPI::Unit>(self)->hasPath(position_to_bw(target));
}

bool Unit_hasPath_Unit(Unit* self, Unit* target) {
    return reinterpret_cast<BWAPI::Unit>(self)->hasPath(reinterpret_cast<BWAPI::Unit>(target));
}

int Unit_getLastCommandFrame(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getLastCommandFrame();
}

UnitCommand Unit_getLastCommand(Unit* self) {
    return unitcommand_from_bw( reinterpret_cast<BWAPI::Unit>(self)->getLastCommand() );
}

Player* Unit_getLastAttackingPlayer(Unit* self) {
    return reinterpret_cast<Player*>( reinterpret_cast<BWAPI::Unit>(self)->getLastAttackingPlayer() );
}

UnitType Unit_getInitialType(Unit* self) {
    return unittype_from_bw( reinterpret_cast<BWAPI::Unit>(self)->getInitialType() );
}

Position Unit_getInitialPosition(Unit* self) {
    return position_from_bw( reinterpret_cast<BWAPI::Unit>(self)->getInitialPosition() );
}

TilePosition Unit_getInitialTilePosition(Unit* self) {
    return tileposition_from_bw( reinterpret_cast<BWAPI::Unit>(self)->getInitialTilePosition() );
}

int Unit_getInitialHitPoints(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getInitialHitPoints();
}

int Unit_getInitialResources(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getInitialResources();
}

int Unit_getKillCount(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getKillCount();
}

int Unit_getAcidSporeCount(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getAcidSporeCount();
}

int Unit_getInterceptorCount(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getInterceptorCount();
}

int Unit_getScarabCount(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getScarabCount();
}

int Unit_getSpiderMineCount(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getSpiderMineCount();
}

int Unit_getGroundWeaponCooldown(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getGroundWeaponCooldown();
}

int Unit_getAirWeaponCooldown(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getAirWeaponCooldown();
}

int Unit_getSpellCooldown(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getSpellCooldown();
}

int Unit_getDefenseMatrixPoints(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getDefenseMatrixPoints();
}

int Unit_getDefenseMatrixTimer(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getDefenseMatrixTimer();
}

int Unit_getEnsnareTimer(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getEnsnareTimer();
}

int Unit_getIrradiateTimer(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getIrradiateTimer();
}

int Unit_getLockdownTimer(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getLockdownTimer();
}

int Unit_getMaelstromTimer(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getMaelstromTimer();
}

int Unit_getOrderTimer(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getOrderTimer();
}

int Unit_getPlagueTimer(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getPlagueTimer();
}

int Unit_getRemoveTimer(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getRemoveTimer();
}

int Unit_getStasisTimer(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getStasisTimer();
}

int Unit_getStimTimer(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getStimTimer();
}

UnitType Unit_getBuildType(Unit* self) {
    return unittype_from_bw( reinterpret_cast<BWAPI::Unit>(self)->getBuildType() );
}

TechType Unit_getTech(Unit* self) {
    return techtype_from_bw( reinterpret_cast<BWAPI::Unit>(self)->getTech() );
}

UpgradeType Unit_getUpgrade(Unit* self) {
    return upgradetype_from_bw( reinterpret_cast<BWAPI::Unit>(self)->getUpgrade() );
}

int Unit_getRemainingBuildTime(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getRemainingBuildTime();
}

int Unit_getRemainingTrainTime(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getRemainingTrainTime();
}

int Unit_getRemainingResearchTime(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getRemainingResearchTime();
}

int Unit_getRemainingUpgradeTime(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getRemainingUpgradeTime();
}

Unit* Unit_getBuildUnit(Unit* self) {
    return reinterpret_cast<Unit*>( reinterpret_cast<BWAPI::Unit>(self)->getBuildUnit() );
}

Unit* Unit_getTarget(Unit* self) {
    return reinterpret_cast<Unit*>( reinterpret_cast<BWAPI::Unit>(self)->getTarget() );
}

Position Unit_getTargetPosition(Unit* self) {
    return position_from_bw( reinterpret_cast<BWAPI::Unit>(self)->getTargetPosition() );
}

Order Unit_getOrder(Unit* self) {
    return order_from_bw( reinterpret_cast<BWAPI::Unit>(self)->getOrder() );
}

Order Unit_getSecondaryOrder(Unit* self) {
    return order_from_bw( reinterpret_cast<BWAPI::Unit>(self)->getSecondaryOrder() );
}

Unit* Unit_getOrderTarget(Unit* self) {
    return reinterpret_cast<Unit*>( reinterpret_cast<BWAPI::Unit>(self)->getOrderTarget() );
}

Position Unit_getOrderTargetPosition(Unit* self) {
    return position_from_bw( reinterpret_cast<BWAPI::Unit>(self)->getOrderTargetPosition() );
}

Position Unit_getRallyPosition(Unit* self) {
    return position_from_bw( reinterpret_cast<BWAPI::Unit>(self)->getRallyPosition() );
}

Unit* Unit_getRallyUnit(Unit* self) {
    return reinterpret_cast<Unit*>( reinterpret_cast<BWAPI::Unit>(self)->getRallyUnit() );
}

Unit* Unit_getAddon(Unit* self) {
    return reinterpret_cast<Unit*>( reinterpret_cast<BWAPI::Unit>(self)->getAddon() );
}

Unit* Unit_getNydusExit(Unit* self) {
    return reinterpret_cast<Unit*>( reinterpret_cast<BWAPI::Unit>(self)->getNydusExit() );
}

Unit* Unit_getPowerUp(Unit* self) {
    return reinterpret_cast<Unit*>( reinterpret_cast<BWAPI::Unit>(self)->getPowerUp() );
}

Unit* Unit_getTransport(Unit* self) {
    return reinterpret_cast<Unit*>( reinterpret_cast<BWAPI::Unit>(self)->getTransport() );
}

UnitIterator* Unit_getLoadedUnits(Unit* self) {
    auto&& units = reinterpret_cast<BWAPI::Unit>(self)->getLoadedUnits();
    return into_iter<UnitIterator>(std::move(units));
}

int Unit_getSpaceRemaining(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->getSpaceRemaining();
}

Unit* Unit_getCarrier(Unit* self) {
    return reinterpret_cast<Unit*>( reinterpret_cast<BWAPI::Unit>(self)->getCarrier() );
}

UnitIterator* Unit_getInterceptors(Unit* self) {
    auto&& interceptors = reinterpret_cast<BWAPI::Unit>(self)->getInterceptors();
    return into_iter<UnitIterator>(std::move(interceptors));
}

Unit* Unit_getHatchery(Unit* self) {
    return reinterpret_cast<Unit*>( reinterpret_cast<BWAPI::Unit>(self)->getHatchery() );
}

UnitIterator* Unit_getLarva(Unit* self) {
    auto&& larva = reinterpret_cast<BWAPI::Unit>(self)->getLarva();
    return into_iter<UnitIterator>(std::move(larva));
}

UnitIterator* Unit_getUnitsInRadius(Unit* self, int radius, UnaryUnitFilter pred) {
    auto pred_filter = reinterpret_cast<bool (*)(BWAPI::Unit)>(pred);
    auto&& units = reinterpret_cast<BWAPI::Unit>(self)->getUnitsInRadius(radius, pred_filter);
    return into_iter<UnitIterator>(std::move(units));
}

UnitIterator* Unit_getUnitsInWeaponRange(Unit* self, WeaponType weapon, UnaryUnitFilter pred) {
    auto pred_filter = reinterpret_cast<bool (*)(BWAPI::Unit)>(pred);
    auto&& units = reinterpret_cast<BWAPI::Unit>(self)->getUnitsInWeaponRange(weapontype_to_bw(weapon), pred_filter);
    return into_iter<UnitIterator>(std::move(units));
}

Unit* Unit_getClosestUnit(Unit* self, UnaryUnitFilter pred, int radius) {
    auto pred_filter = reinterpret_cast<bool (*)(BWAPI::Unit)>(pred);
    auto unit = reinterpret_cast<BWAPI::Unit>(self)->getClosestUnit(pred_filter, radius);
    return reinterpret_cast<Unit*>(unit);
}

bool Unit_hasNuke(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->hasNuke();
}

bool Unit_isAccelerating(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isAccelerating();
}

bool Unit_isAttacking(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isAttacking();
}

bool Unit_isAttackFrame(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isAttackFrame();
}

bool Unit_isBeingConstructed(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isBeingConstructed();
}

bool Unit_isBeingGathered(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isBeingGathered();
}

bool Unit_isBeingHealed(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isBeingHealed();
}

bool Unit_isBlind(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isBlind();
}

bool Unit_isBraking(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isBraking();
}

bool Unit_isBurrowed(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isBurrowed();
}

bool Unit_isCarryingGas(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isCarryingGas();
}

bool Unit_isCarryingMinerals(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isCarryingMinerals();
}

bool Unit_isCloaked(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isCloaked();
}

bool Unit_isCompleted(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isCompleted();
}

bool Unit_isConstructing(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isConstructing();
}

bool Unit_isDefenseMatrixed(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isDefenseMatrixed();
}

bool Unit_isDetected(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isDetected();
}

bool Unit_isEnsnared(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isEnsnared();
}

bool Unit_isFlying(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isFlying();
}

bool Unit_isFollowing(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isFollowing();
}

bool Unit_isGatheringGas(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isGatheringGas();
}

bool Unit_isGatheringMinerals(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isGatheringMinerals();
}

bool Unit_isHallucination(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isHallucination();
}

bool Unit_isHoldingPosition(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isHoldingPosition();
}

bool Unit_isIdle(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isIdle();
}

bool Unit_isInterruptible(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isInterruptible();
}

bool Unit_isInvincible(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isInvincible();
}

bool Unit_isInWeaponRange(Unit* self, Unit* target) {
    return reinterpret_cast<BWAPI::Unit>(self)->isInWeaponRange(reinterpret_cast<BWAPI::Unit>(target));
}

bool Unit_isIrradiated(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isIrradiated();
}

bool Unit_isLifted(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isLifted();
}

bool Unit_isLoaded(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isLoaded();
}

bool Unit_isLockedDown(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isLockedDown();
}

bool Unit_isMaelstrommed(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isMaelstrommed();
}

bool Unit_isMorphing(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isMorphing();
}

bool Unit_isMoving(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isMoving();
}

bool Unit_isParasited(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isParasited();
}

bool Unit_isPatrolling(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isPatrolling();
}

bool Unit_isPlagued(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isPlagued();
}

bool Unit_isRepairing(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isRepairing();
}

bool Unit_isResearching(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isResearching();
}

bool Unit_isSelected(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isSelected();
}

bool Unit_isSieged(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isSieged();
}

bool Unit_isStartingAttack(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isStartingAttack();
}

bool Unit_isStasised(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isStasised();
}

bool Unit_isStimmed(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isStimmed();
}

bool Unit_isStuck(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isStuck();
}

bool Unit_isTraining(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isTraining();
}

bool Unit_isUnderAttack(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isUnderAttack();
}

bool Unit_isUnderDarkSwarm(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isUnderDarkSwarm();
}

bool Unit_isUnderDisruptionWeb(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isUnderDisruptionWeb();
}

bool Unit_isUnderStorm(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isUnderStorm();
}

bool Unit_isPowered(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isPowered();
}

bool Unit_isUpgrading(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isUpgrading();
}

bool Unit_isVisible(Unit* self, Player* player) {
    return reinterpret_cast<BWAPI::Unit>(self)->isVisible(reinterpret_cast<BWAPI::Player>(player));
}

bool Unit_isTargetable(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->isTargetable();
}

bool Unit_issueCommand(Unit* self, UnitCommand command) {
    return reinterpret_cast<BWAPI::Unit>(self)->issueCommand(unitcommand_to_bw(command));
}

bool Unit_attack_Position(Unit* self, Position target, bool shiftQueueCommand) {
    return reinterpret_cast<BWAPI::Unit>(self)->attack(position_to_bw(target), shiftQueueCommand);
}

bool Unit_attack_Unit(Unit* self, Unit* target, bool shiftQueueCommand) {
    return reinterpret_cast<BWAPI::Unit>(self)->attack(reinterpret_cast<BWAPI::Unit>(target), shiftQueueCommand);
}

bool Unit_build(Unit* self, UnitType type, TilePosition target) {
    return reinterpret_cast<BWAPI::Unit>(self)->build(unittype_to_bw(type), tileposition_to_bw(target));
}

bool Unit_buildAddon(Unit* self, UnitType type) {
    return reinterpret_cast<BWAPI::Unit>(self)->buildAddon(unittype_to_bw(type));
}

bool Unit_train(Unit* self, UnitType type) {
    return reinterpret_cast<BWAPI::Unit>(self)->train(unittype_to_bw(type));
}

bool Unit_morph(Unit* self, UnitType type) {
    return reinterpret_cast<BWAPI::Unit>(self)->morph(unittype_to_bw(type));
}

bool Unit_research(Unit* self, TechType tech) {
    return reinterpret_cast<BWAPI::Unit>(self)->research(techtype_to_bw(tech));
}

bool Unit_upgrade(Unit* self, UpgradeType upgrade) {
    return reinterpret_cast<BWAPI::Unit>(self)->upgrade(upgradetype_to_bw(upgrade));
}

bool Unit_setRallyPoint_Position(Unit* self, Position target) {
    return reinterpret_cast<BWAPI::Unit>(self)->setRallyPoint(position_to_bw(target));
}

bool Unit_setRallyPoint_Target(Unit* self, Unit* target) {
    return reinterpret_cast<BWAPI::Unit>(self)->setRallyPoint(reinterpret_cast<BWAPI::Unit>(target));
}

bool Unit_move(Unit* self, Position target, bool shiftQueueCommand) {
    return reinterpret_cast<BWAPI::Unit>(self)->move(position_to_bw(target), shiftQueueCommand);
}

bool Unit_patrol(Unit* self, Position target, bool shiftQueueCommand) {
    return reinterpret_cast<BWAPI::Unit>(self)->patrol(position_to_bw(target), shiftQueueCommand);
}

bool Unit_holdPosition(Unit* self, bool shiftQueueCommand) {
    return reinterpret_cast<BWAPI::Unit>(self)->holdPosition(shiftQueueCommand);
}

bool Unit_stop(Unit* self, bool shiftQueueCommand) {
    return reinterpret_cast<BWAPI::Unit>(self)->stop(shiftQueueCommand);
}

bool Unit_follow(Unit* self, Unit* target, bool shiftQueueCommand) {
    return reinterpret_cast<BWAPI::Unit>(self)->follow(reinterpret_cast<BWAPI::Unit>(target), shiftQueueCommand);
}

bool Unit_gather(Unit* self, Unit* target, bool shiftQueueCommand) {
    return reinterpret_cast<BWAPI::Unit>(self)->gather(reinterpret_cast<BWAPI::Unit>(target), shiftQueueCommand);
}

bool Unit_returnCargo(Unit* self, bool shiftQueueCommand) {
    return reinterpret_cast<BWAPI::Unit>(self)->returnCargo(shiftQueueCommand);
}

bool Unit_repair(Unit* self, Unit* target, bool shiftQueueCommand) {
    return reinterpret_cast<BWAPI::Unit>(self)->repair(reinterpret_cast<BWAPI::Unit>(target), shiftQueueCommand);
}

bool Unit_burrow(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->burrow();
}

bool Unit_unburrow(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->unburrow();
}

bool Unit_cloak(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->cloak();
}

bool Unit_decloak(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->decloak();
}

bool Unit_siege(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->siege();
}

bool Unit_unsiege(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->unsiege();
}

bool Unit_lift(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->lift();
}

bool Unit_land(Unit* self, TilePosition target) {
    return reinterpret_cast<BWAPI::Unit>(self)->land(tileposition_to_bw(target));
}

bool Unit_load(Unit* self, Unit* target, bool shiftQueueCommand) {
    return reinterpret_cast<BWAPI::Unit>(self)->load(reinterpret_cast<BWAPI::Unit>(target), shiftQueueCommand);
}

bool Unit_unload(Unit* self, Unit* target) {
    return reinterpret_cast<BWAPI::Unit>(self)->unload(reinterpret_cast<BWAPI::Unit>(target));
}

bool Unit_unloadAll(Unit* self, bool shiftQueueCommand) {
    return reinterpret_cast<BWAPI::Unit>(self)->unloadAll(shiftQueueCommand);
}

bool Unit_unloadAll_Position(Unit* self, Position target, bool shiftQueueCommand) {
    return reinterpret_cast<BWAPI::Unit>(self)->unloadAll(position_to_bw(target), shiftQueueCommand);
}

bool Unit_rightClick_Position(Unit* self, Position target, bool shiftQueueCommand) {
    return reinterpret_cast<BWAPI::Unit>(self)->rightClick(position_to_bw(target), shiftQueueCommand);
}

bool Unit_rightClick_Unit(Unit* self, Unit* target, bool shiftQueueCommand) {
    return reinterpret_cast<BWAPI::Unit>(self)->rightClick(reinterpret_cast<BWAPI::Unit>(target), shiftQueueCommand);
}

bool Unit_haltConstruction(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->haltConstruction();
}

bool Unit_cancelConstruction(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->cancelConstruction();
}

bool Unit_cancelAddon(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->cancelAddon();
}

bool Unit_cancelTrain(Unit* self, int slot) {
    return reinterpret_cast<BWAPI::Unit>(self)->cancelTrain(slot);
}

bool Unit_cancelMorph(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->cancelMorph();
}

bool Unit_cancelResearch(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->cancelResearch();
}

bool Unit_cancelUpgrade(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->cancelUpgrade();
}

bool Unit_useTech_Position(Unit* self, TechType tech, Position target) {
    return reinterpret_cast<BWAPI::Unit>(self)->useTech(techtype_to_bw(tech), position_to_bw(target));
}

bool Unit_useTech_Unit(Unit* self, TechType tech, Unit* target) {
    return reinterpret_cast<BWAPI::Unit>(self)->useTech(techtype_to_bw(tech), reinterpret_cast<BWAPI::Unit>(target));
}

bool Unit_placeCOP(Unit* self, TilePosition target) {
    return reinterpret_cast<BWAPI::Unit>(self)->placeCOP(tileposition_to_bw(target));
}

bool Unit_canIssueCommand(Unit* self, UnitCommand command, bool checkCanUseTechPositionOnPositions, bool checkCanUseTechUnitOnUnits, bool checkCanBuildUnitType, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canIssueCommand(unitcommand_to_bw(command), checkCanUseTechPositionOnPositions, checkCanUseTechUnitOnUnits, checkCanBuildUnitType, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canIssueCommandGrouped(Unit* self, UnitCommand command, bool checkCanUseTechPositionOnPositions, bool checkCanUseTechUnitOnUnits, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibilityGrouped, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canIssueCommandGrouped(unitcommand_to_bw(command), checkCanUseTechPositionOnPositions, checkCanUseTechUnitOnUnits, checkCanTargetUnit, checkCanIssueCommandType, checkCommandibilityGrouped, checkCommandibility);
}

bool Unit_canCommand(Unit* self) {
    return reinterpret_cast<BWAPI::Unit>(self)->canCommand();
}

bool Unit_canCommandGrouped(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canCommandGrouped(checkCommandibility);
}

bool Unit_canIssueCommandType(Unit* self, UnitCommandType ct, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canIssueCommandType(unitcommandtype_to_bw(ct), checkCommandibility);
}

bool Unit_canIssueCommandTypeGrouped(Unit* self, UnitCommandType ct, bool checkCommandibilityGrouped, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canIssueCommandTypeGrouped(unitcommandtype_to_bw(ct), checkCommandibilityGrouped, checkCommandibility);
}

bool Unit_canTargetUnit(Unit* self, Unit* targetUnit, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canTargetUnit(reinterpret_cast<BWAPI::Unit>(targetUnit), checkCommandibility);
}

bool Unit_canAttack(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canAttack(checkCommandibility);
}

bool Unit_canAttack_Position(Unit* self, Position target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canAttack(position_to_bw(target), checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canAttack_Unit(Unit* self, Unit* target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canAttack(reinterpret_cast<BWAPI::Unit>(target), checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canAttackGrouped(Unit* self, bool checkCommandibilityGrouped, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canAttackGrouped(checkCommandibilityGrouped, checkCommandibility);
}

bool Unit_canAttackGrouped_Position(Unit* self, Position target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibilityGrouped, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canAttackGrouped(position_to_bw(target), checkCanTargetUnit, checkCanIssueCommandType, checkCommandibilityGrouped, checkCommandibility);
}

bool Unit_canAttackGrouped_Unit(Unit* self, Unit* target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibilityGrouped, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canAttackGrouped(reinterpret_cast<BWAPI::Unit>(target), checkCanTargetUnit, checkCanIssueCommandType, checkCommandibilityGrouped, checkCommandibility);
}

bool Unit_canAttackMove(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canAttackMove(checkCommandibility);
}

bool Unit_canAttackMoveGrouped(Unit* self, bool checkCommandibilityGrouped, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canAttackMoveGrouped(checkCommandibilityGrouped, checkCommandibility);
}

bool Unit_canAttackUnit(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canAttackUnit(checkCommandibility);
}

bool Unit_canAttackUnit_Unit(Unit* self, Unit* targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canAttackUnit(reinterpret_cast<BWAPI::Unit>(targetUnit), checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canAttackUnitGrouped(Unit* self, bool checkCommandibilityGrouped, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canAttackUnitGrouped(checkCommandibilityGrouped, checkCommandibility);
}

bool Unit_canAttackUnitGrouped_Unit(Unit* self, Unit* targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibilityGrouped, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canAttackUnitGrouped(reinterpret_cast<BWAPI::Unit>(targetUnit), checkCanTargetUnit, checkCanIssueCommandType, checkCommandibilityGrouped, checkCommandibility);
}

bool Unit_canBuild(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canBuild(checkCommandibility);
}

bool Unit_canBuild_UnitType(Unit* self, UnitType uType, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canBuild(unittype_to_bw(uType), checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canBuild_UnitType_TilePosition(Unit* self, UnitType uType, TilePosition tilePos, bool checkTargetUnitType, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canBuild(unittype_to_bw(uType), tileposition_to_bw(tilePos), checkTargetUnitType, checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canBuildAddon(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canBuildAddon(checkCommandibility);
}

bool Unit_canBuildAddon_UnitType(Unit* self, UnitType uType, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canBuildAddon(unittype_to_bw(uType), checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canTrain(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canTrain(checkCommandibility);
}

bool Unit_canTrain_UnitType(Unit* self, UnitType uType, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canTrain(unittype_to_bw(uType), checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canMorph(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canMorph(checkCommandibility);
}

bool Unit_canMorph_UnitType(Unit* self, UnitType uType, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canMorph(unittype_to_bw(uType), checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canResearch(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canResearch(checkCommandibility);
}

bool Unit_canResearch_TechType(Unit* self, TechType type, bool checkCanIssueCommandType) {
    return reinterpret_cast<BWAPI::Unit>(self)->canResearch(techtype_to_bw(type), checkCanIssueCommandType);
}

bool Unit_canUpgrade(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canUpgrade(checkCommandibility);
}

bool Unit_canUpgrade_UpgradeType(Unit* self, UpgradeType type, bool checkCanIssueCommandType) {
    return reinterpret_cast<BWAPI::Unit>(self)->canUpgrade(upgradetype_to_bw(type), checkCanIssueCommandType);
}

bool Unit_canSetRallyPoint(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canSetRallyPoint(checkCommandibility);
}

bool Unit_canSetRallyPoint_Position(Unit* self, Position target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canSetRallyPoint(position_to_bw(target), checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canSetRallyPoint_Unit(Unit* self, Unit* target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canSetRallyPoint(reinterpret_cast<BWAPI::Unit>(target), checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canSetRallyPosition(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canSetRallyPosition(checkCommandibility);
}

bool Unit_canSetRallyUnit(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canSetRallyUnit(checkCommandibility);
}

bool Unit_canSetRallyUnit_Unit(Unit* self, Unit* targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canSetRallyUnit(reinterpret_cast<BWAPI::Unit>(targetUnit), checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canMove(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canMove(checkCommandibility);
}

bool Unit_canMoveGrouped(Unit* self, bool checkCommandibilityGrouped, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canMoveGrouped(checkCommandibilityGrouped, checkCommandibility);
}

bool Unit_canPatrol(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canPatrol(checkCommandibility);
}

bool Unit_canPatrolGrouped(Unit* self, bool checkCommandibilityGrouped, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canPatrolGrouped(checkCommandibilityGrouped, checkCommandibility);
}

bool Unit_canFollow(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canFollow(checkCommandibility);
}

bool Unit_canFollow_Unit(Unit* self, Unit* targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canFollow(reinterpret_cast<BWAPI::Unit>(targetUnit), checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canGather(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canGather(checkCommandibility);
}

bool Unit_canGather_Unit(Unit* self, Unit* targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canGather(reinterpret_cast<BWAPI::Unit>(targetUnit), checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canReturnCargo(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canReturnCargo(checkCommandibility);
}

bool Unit_canHoldPosition(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canHoldPosition(checkCommandibility);
}

bool Unit_canStop(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canStop(checkCommandibility);
}

bool Unit_canRepair(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canRepair(checkCommandibility);
}

bool Unit_canRepair_Unit(Unit* self, Unit* targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canRepair(reinterpret_cast<BWAPI::Unit>(targetUnit), checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canBurrow(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canBurrow(checkCommandibility);
}

bool Unit_canUnburrow(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canUnburrow(checkCommandibility);
}

bool Unit_canCloak(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canCloak(checkCommandibility);
}

bool Unit_canDecloak(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canDecloak(checkCommandibility);
}

bool Unit_canSiege(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canSiege(checkCommandibility);
}

bool Unit_canUnsiege(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canUnsiege(checkCommandibility);
}

bool Unit_canLift(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canLift(checkCommandibility);
}

bool Unit_canLand(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canLand(checkCommandibility);
}

bool Unit_canLand_TilePosition(Unit* self, TilePosition target, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canLand(tileposition_to_bw(target), checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canLoad(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canLoad(checkCommandibility);
}

bool Unit_canLoad_Unit(Unit* self, Unit* targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canLoad(reinterpret_cast<BWAPI::Unit>(targetUnit), checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canUnloadWithOrWithoutTarget(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canUnloadWithOrWithoutTarget(checkCommandibility);
}

bool Unit_canUnloadAtPosition(Unit* self, Position targDropPos, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canUnloadAtPosition(position_to_bw(targDropPos), checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canUnload(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canUnload(checkCommandibility);
}

bool Unit_canUnload_Unit(Unit* self, Unit* targetUnit, bool checkCanTargetUnit, bool checkPosition, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canUnload(reinterpret_cast<BWAPI::Unit>(targetUnit), checkCanTargetUnit, checkPosition, checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canUnloadAll(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canUnloadAll(checkCommandibility);
}

bool Unit_canUnloadAllPosition(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canUnloadAllPosition(checkCommandibility);
}

bool Unit_canUnloadAllPosition_Position(Unit* self, Position targDropPos, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canUnloadAllPosition(position_to_bw(targDropPos), checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canRightClick(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canRightClick(checkCommandibility);
}

bool Unit_canRightClick_Position(Unit* self, Position target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canRightClick(position_to_bw(target), checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canRightClick_Unit(Unit* self, Unit* target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canRightClick(reinterpret_cast<BWAPI::Unit>(target), checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canRightClickGrouped(Unit* self, bool checkCommandibilityGrouped, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canRightClickGrouped(checkCommandibilityGrouped, checkCommandibility);
}

bool Unit_canRightClickGrouped_Position(Unit* self, Position target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibilityGrouped, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canRightClickGrouped(position_to_bw(target), checkCanTargetUnit, checkCanIssueCommandType, checkCommandibilityGrouped, checkCommandibility);
}

bool Unit_canRightClickGrouped_Unit(Unit* self, Unit* target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibilityGrouped, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canRightClickGrouped(reinterpret_cast<BWAPI::Unit>(target), checkCanTargetUnit, checkCanIssueCommandType, checkCommandibilityGrouped, checkCommandibility);
}

bool Unit_canRightClickPosition(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canRightClickPosition(checkCommandibility);
}

bool Unit_canRightClickPositionGrouped(Unit* self, bool checkCommandibilityGrouped, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canRightClickPositionGrouped(checkCommandibilityGrouped, checkCommandibility);
}

bool Unit_canRightClickUnit(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canRightClickUnit(checkCommandibility);
}

bool Unit_canRightClickUnit_Unit(Unit* self, Unit* targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canRightClickUnit(reinterpret_cast<BWAPI::Unit>(targetUnit), checkCanTargetUnit, checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canRightClickUnitGrouped(Unit* self, bool checkCommandibilityGrouped, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canRightClickUnitGrouped(checkCommandibilityGrouped, checkCommandibility);
}

bool Unit_canRightClickUnitGrouped_Unit(Unit* self, Unit* targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibilityGrouped, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canRightClickUnitGrouped(reinterpret_cast<BWAPI::Unit>(targetUnit), checkCanTargetUnit, checkCanIssueCommandType, checkCommandibilityGrouped, checkCommandibility);
}

bool Unit_canHaltConstruction(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canHaltConstruction(checkCommandibility);
}

bool Unit_canCancelConstruction(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canCancelConstruction(checkCommandibility);
}

bool Unit_canCancelAddon(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canCancelAddon(checkCommandibility);
}

bool Unit_canCancelTrain(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canCancelTrain(checkCommandibility);
}

bool Unit_canCancelTrainSlot(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canCancelTrainSlot(checkCommandibility);
}

bool Unit_canCancelTrainSlot_Check(Unit* self, int slot, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canCancelTrainSlot(slot, checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canCancelMorph(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canCancelMorph(checkCommandibility);
}

bool Unit_canCancelResearch(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canCancelResearch(checkCommandibility);
}

bool Unit_canCancelUpgrade(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canCancelUpgrade(checkCommandibility);
}

bool Unit_canUseTechWithOrWithoutTarget(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canUseTechWithOrWithoutTarget(checkCommandibility);
}

bool Unit_canUseTechWithOrWithoutTarget_TechType(Unit* self, TechType tech, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canUseTechWithOrWithoutTarget(techtype_to_bw(tech), checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canUseTech_Position(Unit* self, TechType tech, Position target, bool checkCanTargetUnit, bool checkTargetsType, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canUseTech(techtype_to_bw(tech), position_to_bw(target), checkCanTargetUnit, checkTargetsType, checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canUseTech_Unit(Unit* self, TechType tech, Unit* target, bool checkCanTargetUnit, bool checkTargetsType, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canUseTech(techtype_to_bw(tech), reinterpret_cast<BWAPI::Unit>(target), checkCanTargetUnit, checkTargetsType, checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canUseTechWithoutTarget(Unit* self, TechType tech, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canUseTechWithoutTarget(techtype_to_bw(tech), checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canUseTechUnit(Unit* self, TechType tech, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canUseTechUnit(techtype_to_bw(tech), checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canUseTechUnit_Unit(Unit* self, TechType tech, Unit* targetUnit, bool checkCanTargetUnit, bool checkTargetsUnits, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canUseTechUnit(techtype_to_bw(tech), reinterpret_cast<BWAPI::Unit>(targetUnit), checkCanTargetUnit, checkTargetsUnits, checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canUseTechPosition(Unit* self, TechType tech, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canUseTechPosition(techtype_to_bw(tech), checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canUseTechPosition_Position(Unit* self, TechType tech, Position target, bool checkTargetsPositions, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canUseTechPosition(techtype_to_bw(tech), position_to_bw(target), checkTargetsPositions, checkCanIssueCommandType, checkCommandibility);
}

bool Unit_canPlaceCOP(Unit* self, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canPlaceCOP(checkCommandibility);
}

bool Unit_canPlaceCOP_TilePosition(Unit* self, TilePosition target, bool checkCanIssueCommandType, bool checkCommandibility) {
    return reinterpret_cast<BWAPI::Unit>(self)->canPlaceCOP(tileposition_to_bw(target), checkCanIssueCommandType, checkCommandibility);
}
