#include "enemy.h"
#include "player.h"
#include "object.h"
#include <string>

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

std::string Enemy::printAttack(int dmg){
    char race = print();
    std::string output;
    output = race + " deals " + std::to_string(dmg) + " to player.";
}