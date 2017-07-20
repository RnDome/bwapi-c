#pragma once

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

int Unit_getID(Unit* self);
bool Unit_exists(Unit* self);
int Unit_getReplayID(Unit* self);
Player* Unit_getPlayer(Unit* self);
UnitType Unit_getType(Unit* self);

Position Unit_getPosition(Unit* self);
TilePosition Unit_getTilePosition(Unit* self);
double Unit_getAngle(Unit* self);
double Unit_getVelocityX(Unit* self);
double Unit_getVelocityY(Unit* self);
Region* Unit_getRegion(Unit* self);

int Unit_getLeft(Unit* self);
int Unit_getTop(Unit* self);
int Unit_getRight(Unit* self);
int Unit_getBottom(Unit* self);

int Unit_getHitPoints(Unit* self);
int Unit_getShields(Unit* self);
int Unit_getEnergy(Unit* self);
int Unit_getResources(Unit* self);
int Unit_getResourceGroup(Unit* self);

int Unit_getDistance_Position(Unit* self, Position target);
int Unit_getDistance_Unit(Unit* self, Unit* target);
bool Unit_hasPath_Position(Unit* self, Position target);
bool Unit_hasPath_Unit(Unit* self, Unit* target);

int Unit_getLastCommandFrame(Unit* self);
UnitCommand Unit_getLastCommand(Unit* self);
Player* Unit_getLastAttackingPlayer(Unit* self);

UnitType Unit_getInitialType(Unit* self);
Position Unit_getInitialPosition(Unit* self);
TilePosition Unit_getInitialTilePosition(Unit* self);
int Unit_getInitialHitPoints(Unit* self);
int Unit_getInitialResources(Unit* self);
int Unit_getKillCount(Unit* self);
int Unit_getAcidSporeCount(Unit* self);
int Unit_getInterceptorCount(Unit* self);
int Unit_getScarabCount(Unit* self);
int Unit_getSpiderMineCount(Unit* self);
int Unit_getGroundWeaponCooldown(Unit* self);
int Unit_getAirWeaponCooldown(Unit* self);
int Unit_getSpellCooldown(Unit* self);

int Unit_getDefenseMatrixPoints(Unit* self);
int Unit_getDefenseMatrixTimer(Unit* self);
int Unit_getEnsnareTimer(Unit* self);
int Unit_getIrradiateTimer(Unit* self);
int Unit_getLockdownTimer(Unit* self);
int Unit_getMaelstromTimer(Unit* self);
int Unit_getOrderTimer(Unit* self);
int Unit_getPlagueTimer(Unit* self);
int Unit_getRemoveTimer(Unit* self);
int Unit_getStasisTimer(Unit* self);
int Unit_getStimTimer(Unit* self);

UnitType Unit_getBuildType(Unit* self);
UnitTypeIterator* Unit_getTrainingQueue(Unit* self);
TechType Unit_getTech(Unit* self);
UpgradeType Unit_getUpgrade(Unit* self);
int Unit_getRemainingBuildTime(Unit* self);
int Unit_getRemainingTrainTime(Unit* self);
int Unit_getRemainingResearchTime(Unit* self);
int Unit_getRemainingUpgradeTime(Unit* self);

Unit* Unit_getBuildUnit(Unit* self);
Unit* Unit_getTarget(Unit* self);
Position Unit_getTargetPosition(Unit* self);
Order Unit_getOrder(Unit* self);
Order Unit_getSecondaryOrder(Unit* self);
Unit* Unit_getOrderTarget(Unit* self);
Position Unit_getOrderTargetPosition(Unit* self);
Position Unit_getRallyPosition(Unit* self);
Unit* Unit_getRallyUnit(Unit* self);
Unit* Unit_getAddon(Unit* self);
Unit* Unit_getNydusExit(Unit* self);
Unit* Unit_getPowerUp(Unit* self);
Unit* Unit_getTransport(Unit* self);
UnitIterator* Unit_getLoadedUnits(Unit* self);
int Unit_getSpaceRemaining(Unit* self);
Unit* Unit_getCarrier(Unit* self);
UnitIterator* Unit_getInterceptors(Unit* self);
Unit* Unit_getHatchery(Unit* self);
UnitIterator* Unit_getLarva(Unit* self);
UnitIterator* Unit_getUnitsInRadius(Unit* self, int radius, UnaryUnitFilter pred);
UnitIterator* Unit_getUnitsInWeaponRange(Unit* self, WeaponType weapon, UnaryUnitFilter pred);
Unit* Unit_getClosestUnit(Unit* self, UnaryUnitFilter pred, int radius);
bool Unit_hasNuke(Unit* self);
bool Unit_isAccelerating(Unit* self);
bool Unit_isAttacking(Unit* self);
bool Unit_isAttackFrame(Unit* self);
bool Unit_isBeingConstructed(Unit* self);
bool Unit_isBeingGathered(Unit* self);
bool Unit_isBeingHealed(Unit* self);
bool Unit_isBlind(Unit* self);
bool Unit_isBraking(Unit* self);
bool Unit_isBurrowed(Unit* self);
bool Unit_isCarryingGas(Unit* self);
bool Unit_isCarryingMinerals(Unit* self);
bool Unit_isCloaked(Unit* self);
bool Unit_isCompleted(Unit* self);
bool Unit_isConstructing(Unit* self);
bool Unit_isDefenseMatrixed(Unit* self);
bool Unit_isDetected(Unit* self);
bool Unit_isEnsnared(Unit* self);
bool Unit_isFlying(Unit* self);
bool Unit_isFollowing(Unit* self);
bool Unit_isGatheringGas(Unit* self);
bool Unit_isGatheringMinerals(Unit* self);
bool Unit_isHallucination(Unit* self);
bool Unit_isHoldingPosition(Unit* self);
bool Unit_isIdle(Unit* self);
bool Unit_isInterruptible(Unit* self);
bool Unit_isInvincible(Unit* self);
bool Unit_isInWeaponRange(Unit* self, Unit* target);
bool Unit_isIrradiated(Unit* self);
bool Unit_isLifted(Unit* self);
bool Unit_isLoaded(Unit* self);
bool Unit_isLockedDown(Unit* self);
bool Unit_isMaelstrommed(Unit* self);
bool Unit_isMorphing(Unit* self);
bool Unit_isMoving(Unit* self);
bool Unit_isParasited(Unit* self);
bool Unit_isPatrolling(Unit* self);
bool Unit_isPlagued(Unit* self);
bool Unit_isRepairing(Unit* self);
bool Unit_isResearching(Unit* self);
bool Unit_isSelected(Unit* self);
bool Unit_isSieged(Unit* self);
bool Unit_isStartingAttack(Unit* self);
bool Unit_isStasised(Unit* self);
bool Unit_isStimmed(Unit* self);
bool Unit_isStuck(Unit* self);
bool Unit_isTraining(Unit* self);
bool Unit_isUnderAttack(Unit* self);
bool Unit_isUnderDarkSwarm(Unit* self);
bool Unit_isUnderDisruptionWeb(Unit* self);
bool Unit_isUnderStorm(Unit* self);
bool Unit_isPowered(Unit* self);
bool Unit_isUpgrading(Unit* self);
bool Unit_isVisible(Unit* self, Player* player);
bool Unit_isTargetable(Unit* self);
bool Unit_issueCommand(Unit* self, UnitCommand command);
bool Unit_attack_Position(Unit* self, Position target, bool shiftQueueCommand);
bool Unit_attack_Unit(Unit* self, Unit* target, bool shiftQueueCommand);

bool Unit_build(Unit* self, UnitType type, TilePosition target);
bool Unit_buildAddon(Unit* self, UnitType type);
bool Unit_train(Unit* self, UnitType type);
bool Unit_morph(Unit* self, UnitType type);
bool Unit_research(Unit* self, TechType tech);
bool Unit_upgrade(Unit* self, UpgradeType upgrade);
bool Unit_setRallyPoint_Position(Unit* self, Position target);
bool Unit_setRallyPoint_Target(Unit* self, Unit* target);
bool Unit_move(Unit* self, Position target, bool shiftQueueCommand);
bool Unit_patrol(Unit* self, Position target, bool shiftQueueCommand);
bool Unit_holdPosition(Unit* self, bool shiftQueueCommand);
bool Unit_stop(Unit* self, bool shiftQueueCommand);
bool Unit_follow(Unit* self, Unit* target, bool shiftQueueCommand);

bool Unit_gather(Unit* self, Unit* target, bool shiftQueueCommand);
bool Unit_returnCargo(Unit* self, bool shiftQueueCommand);

bool Unit_repair(Unit* self, Unit* target, bool shiftQueueCommand);

bool Unit_burrow(Unit* self);
bool Unit_unburrow(Unit* self);

bool Unit_cloak(Unit* self);
bool Unit_decloak(Unit* self);

bool Unit_siege(Unit* self);
bool Unit_unsiege(Unit* self);

bool Unit_lift(Unit* self);
bool Unit_land(Unit* self, TilePosition target);

bool Unit_load(Unit* self, Unit* target, bool shiftQueueCommand);
bool Unit_unload(Unit* self, Unit* target);
bool Unit_unloadAll(Unit* self, bool shiftQueueCommand);
bool Unit_unloadAll_Position(Unit* self, Position target, bool shiftQueueCommand);

bool Unit_rightClick_Position(Unit* self, Position target, bool shiftQueueCommand);
bool Unit_rightClick_Unit(Unit* self, Unit* target, bool shiftQueueCommand);

bool Unit_haltConstruction(Unit* self);
bool Unit_cancelConstruction(Unit* self);
bool Unit_cancelAddon(Unit* self);
bool Unit_cancelTrain(Unit* self, int slot);
bool Unit_cancelMorph(Unit* self);
bool Unit_cancelResearch(Unit* self);
bool Unit_cancelUpgrade(Unit* self);

bool Unit_useTech_Position(Unit* self, TechType tech, Position target);
bool Unit_useTech_Unit(Unit* self, TechType tech, Unit* target);

bool Unit_placeCOP(Unit* self, TilePosition target);
bool Unit_canIssueCommand(Unit* self, UnitCommand command, bool checkCanUseTechPositionOnPositions, bool checkCanUseTechUnitOnUnits, bool checkCanBuildUnitType, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canIssueCommandGrouped(Unit* self, UnitCommand command, bool checkCanUseTechPositionOnPositions, bool checkCanUseTechUnitOnUnits, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibilityGrouped, bool checkCommandibility);

bool Unit_canCommand(Unit* self);
bool Unit_canCommandGrouped(Unit* self, bool checkCommandibility);
bool Unit_canIssueCommandType(Unit* self, UnitCommandType ct, bool checkCommandibility);
bool Unit_canIssueCommandTypeGrouped(Unit* self, UnitCommandType ct, bool checkCommandibilityGrouped, bool checkCommandibility);
bool Unit_canTargetUnit(Unit* self, Unit* targetUnit, bool checkCommandibility);
bool Unit_canAttack(Unit* self, bool checkCommandibility);
bool Unit_canAttack_Position(Unit* self, Position target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canAttack_Unit(Unit* self, Unit* target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canAttackGrouped(Unit* self, bool checkCommandibilityGrouped, bool checkCommandibility);
bool Unit_canAttackGrouped_Position(Unit* self, Position target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibilityGrouped, bool checkCommandibility);
bool Unit_canAttackGrouped_Unit(Unit* self, Unit* target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibilityGrouped, bool checkCommandibility);
bool Unit_canAttackMove(Unit* self, bool checkCommandibility);
bool Unit_canAttackMoveGrouped(Unit* self, bool checkCommandibilityGrouped, bool checkCommandibility);

bool Unit_canAttackUnit(Unit* self, bool checkCommandibility);
bool Unit_canAttackUnit_Unit(Unit* self, Unit* targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canAttackUnitGrouped(Unit* self, bool checkCommandibilityGrouped, bool checkCommandibility);
bool Unit_canAttackUnitGrouped_Unit(Unit* self, Unit* targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibilityGrouped, bool checkCommandibility);

bool Unit_canBuild(Unit* self, bool checkCommandibility);
bool Unit_canBuild_UnitType(Unit* self, UnitType uType, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canBuild_UnitType_TilePosition(Unit* self, UnitType uType, TilePosition tilePos, bool checkTargetUnitType, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canBuildAddon(Unit* self, bool checkCommandibility);
bool Unit_canBuildAddon_UnitType(Unit* self, UnitType uType, bool checkCanIssueCommandType, bool checkCommandibility);

bool Unit_canTrain(Unit* self, bool checkCommandibility);
bool Unit_canTrain_UnitType(Unit* self, UnitType uType, bool checkCanIssueCommandType, bool checkCommandibility);

bool Unit_canMorph(Unit* self, bool checkCommandibility);
bool Unit_canMorph_UnitType(Unit* self, UnitType uType, bool checkCanIssueCommandType, bool checkCommandibility);

bool Unit_canResearch(Unit* self, bool checkCommandibility);
bool Unit_canResearch_TechType(Unit* self, TechType type, bool checkCanIssueCommandType);

bool Unit_canUpgrade(Unit* self, bool checkCommandibility);
bool Unit_canUpgrade_UpgradeType(Unit* self, UpgradeType type, bool checkCanIssueCommandType);

bool Unit_canSetRallyPoint(Unit* self, bool checkCommandibility);
bool Unit_canSetRallyPoint_Position(Unit* self, Position target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canSetRallyPoint_Unit(Unit* self, Unit* target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility);

bool Unit_canSetRallyPosition(Unit* self, bool checkCommandibility);
bool Unit_canSetRallyUnit(Unit* self, bool checkCommandibility);
bool Unit_canSetRallyUnit_Unit(Unit* self, Unit* targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility);

bool Unit_canMove(Unit* self, bool checkCommandibility);
bool Unit_canMoveGrouped(Unit* self, bool checkCommandibilityGrouped, bool checkCommandibility);

bool Unit_canPatrol(Unit* self, bool checkCommandibility);
bool Unit_canPatrolGrouped(Unit* self, bool checkCommandibilityGrouped, bool checkCommandibility);

bool Unit_canFollow(Unit* self, bool checkCommandibility);
bool Unit_canFollow_Unit(Unit* self, Unit* targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility);

bool Unit_canGather(Unit* self, bool checkCommandibility);
bool Unit_canGather_Unit(Unit* self, Unit* targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canReturnCargo(Unit* self, bool checkCommandibility);

bool Unit_canHoldPosition(Unit* self, bool checkCommandibility);
bool Unit_canStop(Unit* self, bool checkCommandibility);

bool Unit_canRepair(Unit* self, bool checkCommandibility);
bool Unit_canRepair_Unit(Unit* self, Unit* targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility);

bool Unit_canBurrow(Unit* self, bool checkCommandibility);
bool Unit_canUnburrow(Unit* self, bool checkCommandibility);

bool Unit_canCloak(Unit* self, bool checkCommandibility);
bool Unit_canDecloak(Unit* self, bool checkCommandibility);

bool Unit_canSiege(Unit* self, bool checkCommandibility);
bool Unit_canUnsiege(Unit* self, bool checkCommandibility);

bool Unit_canLift(Unit* self, bool checkCommandibility);
bool Unit_canLand(Unit* self, bool checkCommandibility);
bool Unit_canLand_TilePosition(Unit* self, TilePosition target, bool checkCanIssueCommandType, bool checkCommandibility);

bool Unit_canLoad(Unit* self, bool checkCommandibility);
bool Unit_canLoad_Unit(Unit* self, Unit* targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canUnloadWithOrWithoutTarget(Unit* self, bool checkCommandibility);
bool Unit_canUnloadAtPosition(Unit* self, Position targDropPos, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canUnload(Unit* self, bool checkCommandibility);
bool Unit_canUnload_Unit(Unit* self, Unit* targetUnit, bool checkCanTargetUnit, bool checkPosition, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canUnloadAll(Unit* self, bool checkCommandibility);
bool Unit_canUnloadAllPosition(Unit* self, bool checkCommandibility);
bool Unit_canUnloadAllPosition_Position(Unit* self, Position targDropPos, bool checkCanIssueCommandType, bool checkCommandibility);

bool Unit_canRightClick(Unit* self, bool checkCommandibility);
bool Unit_canRightClick_Position(Unit* self, Position target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canRightClick_Unit(Unit* self, Unit* target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canRightClickGrouped(Unit* self, bool checkCommandibilityGrouped, bool checkCommandibility);
bool Unit_canRightClickGrouped_Position(Unit* self, Position target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibilityGrouped, bool checkCommandibility);
bool Unit_canRightClickGrouped_Unit(Unit* self, Unit* target, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibilityGrouped, bool checkCommandibility);
bool Unit_canRightClickPosition(Unit* self, bool checkCommandibility);
bool Unit_canRightClickPositionGrouped(Unit* self, bool checkCommandibilityGrouped, bool checkCommandibility);
bool Unit_canRightClickUnit(Unit* self, bool checkCommandibility);
bool Unit_canRightClickUnit_Unit(Unit* self, Unit* targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canRightClickUnitGrouped(Unit* self, bool checkCommandibilityGrouped, bool checkCommandibility);
bool Unit_canRightClickUnitGrouped_Unit(Unit* self, Unit* targetUnit, bool checkCanTargetUnit, bool checkCanIssueCommandType, bool checkCommandibilityGrouped, bool checkCommandibility);

bool Unit_canHaltConstruction(Unit* self, bool checkCommandibility);
bool Unit_canCancelConstruction(Unit* self, bool checkCommandibility);
bool Unit_canCancelAddon(Unit* self, bool checkCommandibility);
bool Unit_canCancelTrain(Unit* self, bool checkCommandibility);
bool Unit_canCancelTrainSlot(Unit* self, bool checkCommandibility);
bool Unit_canCancelTrainSlot_Check(Unit* self, int slot, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canCancelMorph(Unit* self, bool checkCommandibility);
bool Unit_canCancelResearch(Unit* self, bool checkCommandibility);
bool Unit_canCancelUpgrade(Unit* self, bool checkCommandibility);

bool Unit_canUseTechWithOrWithoutTarget(Unit* self, bool checkCommandibility);
bool Unit_canUseTechWithOrWithoutTarget_TechType(Unit* self, TechType tech, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canUseTech_Position(Unit* self, TechType tech, Position target, bool checkCanTargetUnit, bool checkTargetsType, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canUseTech_Unit(Unit* self, TechType tech, Unit* target, bool checkCanTargetUnit, bool checkTargetsType, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canUseTechWithoutTarget(Unit* self, TechType tech, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canUseTechUnit(Unit* self, TechType tech, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canUseTechUnit_Unit(Unit* self, TechType tech, Unit* targetUnit, bool checkCanTargetUnit, bool checkTargetsUnits, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canUseTechPosition(Unit* self, TechType tech, bool checkCanIssueCommandType, bool checkCommandibility);
bool Unit_canUseTechPosition_Position(Unit* self, TechType tech, Position target, bool checkTargetsPositions, bool checkCanIssueCommandType, bool checkCommandibility);

bool Unit_canPlaceCOP(Unit* self, bool checkCommandibility);
bool Unit_canPlaceCOP_TilePosition(Unit* self, TilePosition target, bool checkCanIssueCommandType, bool checkCommandibility);
void Unit_registerEvent(Unit* self, void (*const action)(Unit*), bool (*const condition)(Unit*), int timesToRun, int framesToCheck);

#ifdef __cplusplus
}
#endif
