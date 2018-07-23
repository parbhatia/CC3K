#include "drow.h"
#include "halfling.h"
#include "dwarf.h"
#include <ctime>
#include <cstdlib>

Drow::Drow(int atk, int def, int hp): Player{atk, def, hp} {}

void Drow::beAttacked(Object *whoFrom) {
  whoFrom->attack(this);
}

void Drow::attack(Halfling *h) {
  srand(time(NULL));
  int chance = rand()%10 + 1;
  if (chance > 5) {   // Halfling has 50% chance to cause PC to miss.
    h->changeHp(-getAtk() * 100 / (100 + h->getDef())); 
  }
}

void Drow::attack(Dwarf *d) {
  srand(time(NULL));
  int chance = rand()%10 + 1;
  if (chance > getMissChance()) {
    d->changeHp(-getAtk() * 100 / (100 + d->getDef())); 
  }
}

