#include "vampire.h"
#include <climits>
#include "halfling.h"
#include "dwarf.h"
#include "attack.h"
#include <cstdlib>

Vampire::Vampire(double atk, double def, double hp): Player{atk, def, hp} {
    setMaxHp(INT32_MAX);
}

void Vampire::beAttacked(Object *whoFrom) {
    whoFrom->attack(this);
}

void Vampire::attack(Character *whoTo) {
    int chance = rand() % 10 + 1;
    if (chance > getMissChance()) {
        double dmg = (-getAtk() * 100 / (100 + whoTo->getDef()));
        whoTo->changeHp(dmg);
        if(whoTo->getHp()<=0){
            throw Attack{dmg, 0, Result::death};
        } else {
            throw Attack{dmg, whoTo->getHp(), Result::attack};
        }
        changeHp(5); // Vampire gains 5 HP every successful attack.
    } else {
        throw Attack{0, whoTo->getHp(), Result::miss};
    }
}

void Vampire::attack(Halfling *h) {
    int chance = rand() % 10 + 1;
    if (chance > 5) {   // Halfling has 50% chance to cause PC to miss.
        double dmg = (-getAtk() * 100 / (100 + h->getDef()));
        h->changeHp(dmg);
        changeHp(5);   // Vampire gains 5 HP every successful attack.
        if(h->getHp()<=0){
            throw Attack{dmg, 0, Result::death};
        } else {
            throw Attack{dmg, h->getHp(), Result::attack};
        }
    } else {
        throw Attack{0, h->getHp(), Result::miss};
    }
}

void Vampire::attack(Dwarf *d) {
    int chance = rand() % 10 + 1;
    if (chance > getMissChance()) {
        double dmg = (-getAtk() * 100 / (100 + d->getDef()));
        d->changeHp(dmg);
        changeHp(-5);   // Vampires are allergic to dwarves. lose 5HP instead.
        if(d->getHp()<=0){
            throw Attack{dmg, 0, Result::death};
        } else {
            throw Attack{dmg, d->getHp(), Result::attack};
        }
    } else {
        throw Attack{0, d->getHp(), Result::miss};
    }
}
