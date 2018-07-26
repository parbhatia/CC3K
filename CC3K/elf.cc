#include "elf.h"
#include "drow.h"
#include "goblin.h"

char Elf::print(){
    return 'E';
}

void Elf::beAttacked(Object* whoFrom){
    whoFrom->attack(this);
}

Elf::Elf() : Enemy{30, 10, 140} {    
}

void Elf::attack(Enemy* whoTo){
    int chance;
    double dmg = -getAtk()*100/(100+whoTo->getDef());
    for(int i = 0; i<2; i++){
        chance = rand()%10 + 1;
        if (chance > getMissChance()) {
            whoTo->changeHp(dmg);
        } 
        else {
            dmg = 0;
        }
        Character::storeAction(-dmg, print(), 'P', whoTo->getHp());
    }

}

void Elf::attack(Goblin *g) {
    int chance;
    double dmg = -getAtk()*100/(100+g->getDef());
    for (int i = 0; i < 2; i++) {
        chance = rand()%10 + 1;
        if (chance > getMissChance()) {
            g->changeHp(dmg);
        }
        else{
            dmg = 0;
        }
        Character::storeAction(-dmg, print(), 'P', g->getHp());   
    }
}
