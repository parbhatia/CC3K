#include "dragon.h"
#include "drow.h"
#include "goblin.h"
#include "attack.h"

Dragon::Dragon(): Enemy{20, 20, 150} {}
char Dragon::print() {
    return 'D';
} 
void Dragon::beAttacked(Object* whoFrom) {
    whoFrom->attack(this);
}

void Dragon::attack(Drow *d) {
    if (getHostile()) {
    double dmg = -getAtk()*100/(100+d->getDef());
    int chance = rand()%10 + 1;
    if (chance > getMissChance()) {
        
        d->changeHp(dmg);
        if(d->getHp() <= 0){
            throw Attack{dmg,0,Result::death};
        }
    }
    else{
        dmg = 0;
    }
    Character::storeAction(dmg, print(), 'P', d->getHp);   
    } 
}

void Dragon::attack(Goblin *g) {
    if (getHostile()) {
    double dmg = -getAtk()*100/(100+g->getDef());
    int chance = rand()%10 + 1;
    if (chance > getMissChance()) {
        
        g->changeHp(dmg);
        if(g->getHp()<=0){
            throw Attack{dmg, 0, Result::death};
        }
    }
    else{
        dmg = 0;
    }
    Character::storeAction(dmg, print(), 'P', g->getHp);
    }
}

void Dragon::attack(Character *whoTo) {
    if (getHostile()) {
    double dmg = -getAtk()*100/(100+whoTo->getDef());
    int chance = rand()%10 + 1;
    if (chance > getMissChance()) {    
        whoTo->changeHp(dmg);
        if(whoTo->getHp() <= 0){
            throw Attack{dmg,0,Result::death};
        }
    }
    else{
        dmg = 0;
    }
    Character::storeAction(dmg, print(), 'P', whoTo->getHp);
}   
}

void Dragon::setHostile(bool n) {
    dragon_hostile = n;
}

void Dragon::setDragongold(Gold* g) {
    dragongold = g;
}

Gold* Dragon::getDragongold() {
    return dragongold;
}