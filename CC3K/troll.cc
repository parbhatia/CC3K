#include "troll.h"
#include "halfling.h"
#include "dwarf.h"
#include <cstdlib>

Troll::Troll(int atk, int def, int hp): Player{atk, def, hp} {}

void Troll::beAttacked(Object *whoFrom) {
  whoFrom->attack(this);
}

void Troll::attack(Halfling *h) {
  int chance = rand() % 10 + 1;
  if (chance > 5) {   // Halfling has 50% chance to cause PC to miss.
    h->changeHp(-getAtk() * 100 / (100 + h->getDef())); 
  }
}
void Troll::attack(Dwarf *d) {
  int chance = rand() % 10 + 1;
  if (chance > getMissChance()) {
    d->changeHp(-getAtk() * 100 / (100 + d->getDef())); 
  }
}

