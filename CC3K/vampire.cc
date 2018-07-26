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

void Vampire::attack(Enemy *whoTo) {
    int chance = rand() % 10 + 1;
    double dmg = (-getAtk() * 100 / (100 + whoTo->getDef()));
    if (chance > getMissChance()) {
        whoTo->changeHp(dmg);
        changeHp(5); // Vampire gains 5 HP every successful attack.
    } else {
        dmg = 0;
    }
    Character::storeAction(-dmg, print(), whoTo->print(), whoTo->getHp());
}

void Vampire::attack(Halfling *h) {
    double dmg = (-getAtk() * 100 / (100 + h->getDef()));
    int chance = rand() % 10 + 1;
    if (chance > 5) {   // Halfling has 50% chance to cause PC to miss.
        h->changeHp(dmg);
        changeHp(5);   // Vampire gains 5 HP every successful attack.
    } else {
        dmg = 0;
    }
    Character::storeAction(-dmg, print(), h->print(), h->getHp());
}

void Vampire::attack(Dwarf *d) {
    double dmg = (-getAtk() * 100 / (100 + d->getDef()));
    int chance = rand() % 10 + 1;
    if (chance > getMissChance()) {
        d->changeHp(dmg);
        changeHp(-5);   // Vampires are allergic to dwarves. lose 5HP instead.
    } else {
        dmg = 0;
    }
    Character::storeAction(-dmg, print(), d->print(), d->getHp());
}
