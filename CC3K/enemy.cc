#include "enemy.h"
#include "player.h"
#include "object.h"
#include "drow.h"
#include "goblin.h"

#include <string>
#include <iostream>
using namespace std;

Enemy::Enemy(double atk, double def, double hp): Character{atk, def, hp} {}

Enemy::~Enemy() {}

void Enemy::notify(Player* p) { 
    if (getHostile()) {                  //decide if attack here. check hostile
        p->beAttacked(this);
    }
}

void Enemy::attack(Player *p) {
    double dmg = (-getAtk() * 100 / (100 + p->getDef()));

    int chance = rand() % 10 + 1;
    if (chance > p->getMissChance()) {
        p->changeHp(dmg);
    } else {
        dmg = 0;;
    }
    Character::storeAction(-dmg, print(), 'P', p->getHp());


}


void Enemy::attack(Drow *d) {
    double dmg = -getAtk()*100/(100+d->getDef());
    int chance = rand()%10 + 1;
    if (chance > getMissChance()) {

        d->changeHp(dmg);
    }
    else{
        dmg = 0;
    }
    Character::storeAction(-dmg, print(), 'P', d->getHp());
    
}

void Enemy::attack(Goblin *g) {
    double dmg = -getAtk()*100/(100+g->getDef());
    int chance = rand()%10 + 1;
    if (chance > getMissChance()) {     
        g->changeHp(dmg);
    }
    else{
        dmg = 0;
    }    
    Character::storeAction(-dmg, print(), 'P', g->getHp());
}

void Enemy::setHostile(bool n) {}
bool Enemy::isDead() {
    return (getHp() <= 0);
}
