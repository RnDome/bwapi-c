#include <Bullet.h>
#include <BWAPI/Bullet.h>
#include "Cast.hpp"

int Bullet_getID(Bullet* self) {
    return reinterpret_cast<BWAPI::Bullet>(self)->getID();
}

bool Bullet_exists(Bullet* self) {
    return reinterpret_cast<BWAPI::Bullet>(self)->exists();
}

Player* Bullet_getPlayer(Bullet* self) {
    return reinterpret_cast<Player*>( reinterpret_cast<BWAPI::Bullet>(self)->getPlayer() );
}

BulletType Bullet_getType(Bullet* self) {
    return cast_from_bw( reinterpret_cast<BWAPI::Bullet>(self)->getType() );
}

Unit* Bullet_getSource(Bullet* self) {
    return reinterpret_cast<Unit*>( reinterpret_cast<BWAPI::Bullet>(self)->getSource() );
}

Position Bullet_getPosition(Bullet* self) {
    return cast_from_bw( reinterpret_cast<BWAPI::Bullet>(self)->getPosition() );
}

double Bullet_getAngle(Bullet* self) {
    return reinterpret_cast<BWAPI::Bullet>(self)->getAngle();
}

double Bullet_getVelocityX(Bullet* self) {
    return reinterpret_cast<BWAPI::Bullet>(self)->getVelocityX();
}

double Bullet_getVelocityY(Bullet* self) {
    return reinterpret_cast<BWAPI::Bullet>(self)->getVelocityY();
}

Unit* Bullet_getTarget(Bullet* self) {
    return reinterpret_cast<Unit*>( reinterpret_cast<BWAPI::Bullet>(self)->getTarget() );
}

Position Bullet_getTargetPosition(Bullet* self) {
    return cast_from_bw( reinterpret_cast<BWAPI::Bullet>(self)->getTargetPosition() );
}

int Bullet_getRemoveTimer(Bullet* self) {
    return reinterpret_cast<BWAPI::Bullet>(self)->getRemoveTimer();
}

bool Bullet_isVisible(Bullet* self, Player* player) {
    return reinterpret_cast<BWAPI::Bullet>(self)->isVisible(reinterpret_cast<BWAPI::Player>(player));
}
