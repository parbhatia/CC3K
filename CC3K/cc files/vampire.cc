#include "vampire.h"
#include <climits>
#include "halfling.h"
#include "dwarf.h"
#include "attack.h"
#include <cstdlib>

Vampire::Vampire(int atk, int def, int hp): Player{atk, def, hp} {
    setMaxHp(INT32_MAX);
}

void Vampire::beAttacked(Object *whoFrom) {
  whoFrom->attack(this);
}

void Vampire::attack(Character *whoTo) {
    int chance = rand() % 10 + 1;
    if (chance > getMissChance()) {
    int dmg = (-getAtk() * 100 / (100 + whoTo->getDef()));
    whoTo->changeHp(dmg); 
    changeHp(5);
    }   // Vampire gains 5 HP every successful attack.
}

void Vampire::attack(Halfling *h) {
  int chance = rand() % 10 + 1;
  if (chance > 5) {   // Halfling has 50% chance to cause PC to miss.
    h->changeHp(-getAtk() * 100 / (100 + h->getDef()));  
    changeHp(5);   // Vampire gains 5 HP every successful attack.
  }
}

void Vampire::attack(Dwarf *d) {
  int chance = rand() % 10 + 1;
  if (chance > getMissChance()) {
    d->changeHp(-getAtk() * 100 / (100 + d->getDef())); 
    changeHp(-5);   // Vampires are allergic to dwarves. lose 5HP instead.
  }
}