#include "halfling.h"
#include "attack.h"
#include "goblin.h"
#include "drow.h"

char Halfling::print(){
    return 'L';
}

Halfling::Halfling() : Enemy{15, 20, 100} {}

void Halfling::beAttacked(Object* whoFrom){
    whoFrom->attack(this);
}


void Halfling::attack(Goblin* g){
    double dmg = (-getAtk()*100/(100+g->getDef()));
    int chance = rand()%10 + 1;
    if (chance > getMissChance()) {
        g->changeHp(dmg);
    } else {
        dmg = 0;
    }
    Character::storeAction(dmg, print(), 'P', g->getHp);
}

void Halfling::attack(Drow *h) {
    int chance = rand() % 10 + 1;
    double dmg = (-getAtk() * 100 / (100 + h->getDef()));

    if (chance > h->getMissChance()) {
        h->changeHp(dmg);
    } 
    else {
        dmg = 0;
    }
    Character::storeAction(dmg, print(), 'P', h->getHp);
}