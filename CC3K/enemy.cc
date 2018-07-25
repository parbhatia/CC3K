#include "enemy.h"
#include "player.h"
#include "object.h"

Enemy::Enemy(double atk, double def, double hp): Character{atk, def, hp} {}

Enemy::~Enemy() {}

void Enemy::setHostile(bool n) {
    isHostile = n;
}

bool Enemy::getHostile() {
    return isHostile;
}

void Enemy::notify(Player* p) { 
    p->beAttacked(this);
}
