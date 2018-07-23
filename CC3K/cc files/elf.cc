#include "elf.h"
#include "drow.h"

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
        d->changeHp(-getAtk()*100/(100+d->getDef())); 
    }
}

void Elf::attack(Character* whoTo){
    int chance;
    
    for(int i = 0; i<2; i++){
        chance = rand()%10 + 1;
        if (chance > getMissChance()) {
        whoTo->changeHp(-getAtk()*100/(100+whoTo->getDef())); 
        }
    }

}