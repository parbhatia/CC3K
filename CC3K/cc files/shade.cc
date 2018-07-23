#include "shade.h"
#include "halfling.h"
#include "dwarf.h"
#include <ctime>
#include <cstdlib>

Shade::Shade(int atk, int def, int hp): Player{atk, def, hp} {}

void Shade::beAttacked(Object *whoFrom) {
  whoFrom->attack(this);
}

void Shade::attack(Halfling *h) {
  int chance = rand() % 10 + 1;
  if (chance > 5) {   // Halfling has 50% chance to cause PC to miss.
    h->changeHp(-getAtk() * 100 / (100 + h->getDef())); 
  }
}

void Shade::attack(Dwarf *d) {
  int chance = rand() % 10 + 1;
  if (chance > getMissChance()) {
    d->changeHp(-getAtk() * 100 / (100 + d->getDef())); 
  }
}
