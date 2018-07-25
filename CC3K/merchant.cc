#include "merchant.h"
#include "drow.h"
#include "goblin.h"
#include "attack.h"

Merchant::Merchant(): Enemy{70, 5, 30} {}
char Merchant::print() {
    return 'M';
} 
void Merchant::beAttacked(Object* whoFrom) {
    whoFrom->attack(this);
}

/*void Merchant::attack(Drow *d) {
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

void Merchant::attack(Goblin *g) {
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

void Merchant::attack(Character *whoTo) {
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
}*/

bool Merchant::getHostile() {
    return merchant_hostile;
}
void Merchant::setHostile(bool n) {
    merchant_hostile = n;
}