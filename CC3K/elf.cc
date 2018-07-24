#include "elf.h"
#include "drow.h"
#include "goblin.h"
#include "attack.h"

char Elf::print(){
    return 'E';
}

void Elf::beAttacked(Object* whoFrom){
    whoFrom->attack(this);
}

Elf::Elf() : Enemy{30, 10, 140} {    
}



void Elf::attack(Drow *d){  //only attack Drow once
    int chance = rand()%10 + 1;
    if (chance > getMissChance()) {
        double dmg = -getAtk()*100/(100+d->getDef());
        d->changeHp(dmg);
        if(d->getHp() <= 0){
            throw Attack{dmg,0,Result::death};
        }
        else{
            throw Attack{dmg, d->getHp(), Result::attack};
        }
    }
    else{
        throw Attack{0, d->getHp(), Result::miss};
    }
}

void Elf::attack(Character* whoTo){
    int chance;
    for(int i = 0; i<2; i++){
        chance = rand()%10 + 1;
        if (chance > getMissChance()) {
            double dmg = -getAtk()*100/(100+whoTo->getDef());
            whoTo->changeHp(dmg);
            if(whoTo->getHp() <= 0){
                throw Attack{dmg,0,Result::death};
            }
            else{
                throw Attack{dmg, whoTo->getHp(), Result::attack};
            }
        }
    }
<<<<<<< HEAD:CC3K/cc files/elf.cc
=======
    
>>>>>>> dd6ffc9a75018b1164dc6163cf7e485d88fdd3ac:CC3K/elf.cc
}

void Elf::attack(Goblin *g) {
<<<<<<< HEAD:CC3K/cc files/elf.cc
    int chance;
    for (int i = 0; i < 2; i++) {
    if (chance > getMissChance()) {
        chance = rand()%10 + 1;
        double dmg = -getAtk()*100/(100+g->getDef());
        g->changeHp(dmg);
        if(g->getHp() <= 0){
            throw Attack{dmg,0,Result::death};
=======
    int chance = rand()%10 + 1;
    for (int i = 0; i < 2; ++i) {
        if (chance > getMissChance()) {
            double dmg = -getAtk()*100/(100+g->getDef());
            g->changeHp(dmg);
            if(g->getHp() <= 0){
                throw Attack{dmg,0,Result::death};
            }
            else{
                throw Attack{dmg, g->getHp(), Result::attack};
            }
>>>>>>> dd6ffc9a75018b1164dc6163cf7e485d88fdd3ac:CC3K/elf.cc
        }
        else{
            throw Attack{0, g->getHp(), Result::miss};
        }
    }
}
