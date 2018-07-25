#include "enemy.h"
#include "player.h"
#include "object.h"
#include <string>
using namespace std;

Enemy::Enemy(double atk, double def, double hp): Character{atk, def, hp} {}

Enemy::~Enemy() {}

void Enemy::notify(Player* p) { 
    if (getHostile()) {
        p->beAttacked(this);
    }
}

