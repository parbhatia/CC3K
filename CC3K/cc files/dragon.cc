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
}

void Dragon::attack(Goblin *g) {
    if (getHostile()) {
    int chance = rand()%10 + 1;
    if (chance > getMissChance()) {
        double dmg = -getAtk()*100/(100+g->getDef());
        g->changeHp(dmg);
        if(g->getHp() <= 0){
            throw Attack{dmg,0,Result::death};
        }
        else{
            throw Attack{dmg, g->getHp(), Result::attack}; 
        }
    }
    else{
        throw Attack{0, g->getHp(), Result::miss};
    }    
    }
}

void Dragon::attack(Character *whoTo) {
    if (getHostile()) {
    int chance = rand()%10 + 1;
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
    else{
        throw Attack{0, whoTo->getHp(), Result::miss};
    } 
    }   
}
