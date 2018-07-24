#include "dwarf.h"
#include "drow.h"
#include "goblin.h"
#include "attack.h"

Dwarf::Dwarf() : Enemy{20, 30, 100} {}

char Dwarf::print(){
    return 'W';
}

void Dwarf::beAttacked(Object* whoFrom) {
    whoFrom->attack(this);
}

void Dwarf::attack(Drow *d) {
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
void Dwarf::attack(Goblin *g) {
    int chance = rand()%10 + 1;
    if (chance > getMissChance()) {
        int dmg = -getAtk()*100/(100+g->getDef());
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
