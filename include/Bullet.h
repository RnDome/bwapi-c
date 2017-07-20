#pragma once

#include <Types.h>

#ifdef __cplusplus
extern "C" {
#endif

int Bullet_getID(Bullet* self);
bool Bullet_exists(Bullet* self);
Player* Bullet_getPlayer(Bullet* self);
BulletType Bullet_getType(Bullet* self);
Unit* Bullet_getSource(Bullet* self);
Position Bullet_getPosition(Bullet* self);
double Bullet_getAngle(Bullet* self);
double Bullet_getVelocityX(Bullet* self);
double Bullet_getVelocityY(Bullet* self);
Unit* Bullet_getTarget(Bullet* self);
Position Bullet_getTargetPosition(Bullet* self);
int Bullet_getRemoveTimer(Bullet* self);
bool Bullet_isVisible(Bullet* self, Player* player);
void Bullet_registerEvent(Bullet* self, void (* const action)(Bullet*), bool (* const condition)(Bullet*), int timesToRun, int framesToCheck);

#ifdef __cplusplus
} // extern "C"
#endif
