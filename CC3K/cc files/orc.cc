#include "orc.h"
#include "attack.h"
#include "goblin.h"

char Orc::print(){
    return 'O';
}

Orc::Orc() : Enemy{30, 25, 180} {
}

void Orc::beAttacked(Object* whoFrom){
    whoFrom->attack(this);
}

void Orc::attack(Goblin* g){
    int chance = rand()%10 + 1;
    if (chance > getMissChance()) {
        int dmg = (-getAtk()*100/(100+g->getDef()))*1.5;
        g->changeHp(dmg);
        if(g->getHp()<=0){
            throw Attack{dmg, 0, Result::death};
        }
        else{
        throw Attack{dmg, g->getHp(), Result::attack};
        }
    } else {
        throw Attack{0, g->getHp(), Result::miss};
    }
}

Orc::~Orc() {}

