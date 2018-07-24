#include "human.h"
#include "attack.h"
#include "goblin.h"
#include "drow.h"

char Human::print(){
    return 'H';
}

Human::Human() : Enemy{20, 20, 140} {}

void Human::beAttacked(Object* whoFrom){
    whoFrom->attack(this);
}

void Human::attack(Goblin* g){
    int chance = rand()%10 + 1;
    if (chance > getMissChance()) {
        int dmg = (-getAtk()*100/(100+g->getDef()));
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

void Human::attack(Drow *h) {
    int chance = rand() % 10 + 1;
    if (chance > h->getMissChance()) {
        int dmg = (-getAtk() * 100 / (100 + h->getDef()));
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