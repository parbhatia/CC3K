#include "vampire.h"
#include <climits>
#include "halfling.h"
#include "dwarf.h"
#include "drow.h"
#include "goblin.h"
#include <ctime>
#include <cstdlib>

Vampire::Vampire(int atk, int def, int hp): Player{atk, def, hp} {
    setMaxHp(INT32_MAX);
}

void Vampire::beAttacked(Object *whoFrom) {
  whoFrom->attack(this);
}

void Vampire::attack(Character *whoTo) {
    srand(time(NULL));
    int chance = rand() % 10 + 1;
    if (chance > getMissChance()) {
    whoTo->changeHp(-getAtk() * 100 / (100 + whoTo->getDef())); 
    changeHp(5);
    }   // Vampire gains 5 HP every successful attack.
}

void Vampire::attack(Halfling *h) {
  srand(time(NULL));
  int chance = rand() % 10 + 1;
  if (chance > 5) {   // Halfling has 50% chance to cause PC to miss.
    h->changeHp(-getAtk() * 100 / (100 + h->getDef()));  
    changeHp(5);   // Vampire gains 5 HP every successful attack.
  }
}

void Vampire::attack(Dwarf *d) {
  srand(time(NULL));
  int chance = rand() % 10 + 1;
  if (chance > getMissChance()) {
    d->changeHp(-getAtk() * 100 / (100 + d->getDef())); 
    changeHp(-5);   // Vampires are allergic to dwarves. lose 5HP instead.
  }
}