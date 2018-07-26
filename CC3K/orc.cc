#include "orc.h"

#include "goblin.h"
#include "drow.h"

char Orc::print(){
    return 'O';
}

Orc::Orc() : Enemy{30, 25, 180} {
}

void Orc::beAttacked(Object* whoFrom){
    whoFrom->attack(this);
}

void Orc::attack(Goblin* g){
    double dmg = (-getAtk()*100/(100+g->getDef()))*1.5;
    int chance = rand()%10 + 1;
    if (chance > getMissChance()) {
        g->changeHp(dmg);
    }
    else {
        dmg = 0;
    }
    Character::storeAction(-dmg, print(), 'P', g->getHp());
}
Orc::~Orc() {}

