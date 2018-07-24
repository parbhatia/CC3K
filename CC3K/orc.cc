#include "orc.h"
#include "attack.h"
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
    int chance = rand()%10 + 1;
    if (chance > getMissChance()) {
        double dmg = (-getAtk()*100/(100+g->getDef()))*1.5;
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

void Orc::attack(Drow *h) {
    int chance = rand() % 10 + 1;
    if (chance > h->getMissChance()) {
        double dmg = (-getAtk() * 100 / (100 + h->getDef()));
        h->changeHp(dmg);
        if(h->getHp()<=0){
            throw Attack{dmg, 0, Result::death};
        }
        else{
            throw Attack{dmg, h->getHp(), Result::attack};
        } 
    } else {
        throw Attack{0, h->getHp(), Result::miss};
    }
}

Orc::~Orc() {}

