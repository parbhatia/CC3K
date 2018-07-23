#include "elf.h"
#include "drow.h"
#include "attack.h"

char Elf::print(){
    return 'E';
}

void Elf::beAttacked(Object* whoFrom){
    whoFrom->attack(this);
}

Elf::Elf() : Enemy{30, 10, 140} {    
}



void Elf::attack(Drow *d){
    int chance = rand()%10 + 1;
    if (chance > getMissChance()) {
        int dmg = -getAtk()*100/(100+d->getDef());
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
            int dmg = -getAtk()*100/(100+whoTo->getDef());
            whoTo->changeHp(dmg);
        if(whoTo->getHp() <= 0){
            throw Attack{dmg,0,Result::death};
        }
        else{
            throw Attack{dmg, whoTo->getHp(), Result::attack}; 
        }
        }
    }

}