#include "shade.h"
#include "halfling.h"
#include "dwarf.h"
#include "attack.h"
#include <cstdlib>
using namespace std;

Shade::Shade(double atk, double def, double hp): Player{atk, def, hp} {}

void Shade::beAttacked(Object *whoFrom) {
    whoFrom->attack(this);
}

void Shade::attack(Halfling *h) {
    int chance = rand() % 10 + 1;
    if (chance > 5) {   // Halfling has 50% chance to cause PC to miss.
        double dmg = (-getAtk() * 100 / (100 + h->getDef()));
        h->changeHp(dmg);
        if(h->getHp()<=0){
            //throw Attack{dmg, 0, Result::death};
        } else {
            //throw Attack{dmg, h->getHp(), Result::attack};
        }
    } else {
        //throw Attack{0, h->getHp(), Result::miss};
    }
}


void Shade::attack(Dwarf *d) {
    int chance = rand() % 10 + 1;
    if (chance > getMissChance()) {
        double dmg = (-getAtk() * 100 / (100 + d->getDef()));
        d->changeHp(dmg);
        stringstream ss;
        if(d->getHp()<=0){
            ss << "PC kills " << d->print() << ".";
            addAction(ss.str());
            //throw Attack{dmg, 0, Result::death};
        } else {
            ss << printAttack(dmg);
            addAction(ss.str());
            //throw Attack{dmg, d->getHp(), Result::attack};
        }
    } else {
        throw Attack{0, d->getHp(), Result::miss};
    }
}
