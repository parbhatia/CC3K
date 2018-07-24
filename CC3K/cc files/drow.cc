#include "drow.h"
#include "halfling.h"
#include "dwarf.h"
#include "attack.h"
#include <cstdlib>

Drow::Drow(int atk, int def, int hp): Player{atk, def, hp} {
  setPotRate(1.5);
}

void Drow::beAttacked(Object *whoFrom) {
  whoFrom->attack(this);
}

void Drow::attack(Halfling *h) {
  int chance = rand() % 10 + 1;

  if (chance > 5) {   // Halfling has 50% chance to cause PC to miss.
    int dmg = (-getAtk() * 100 / (100 + h->getDef()));
    h->changeHp(dmg);
    if(h->getHp()<=0){
      throw Attack{dmg, 0, Result::death};
    } else {
      throw Attack{dmg, h->getHp(), Result::attack};
    } 
  } else {
    throw Attack{0, h->getHp(), Result::miss};
  }
}

void Drow::attack(Dwarf *d) {
  int chance = rand() % 10 + 1;
  if (chance > getMissChance()) {
    int dmg = (-getAtk() * 100 / (100 + d->getDef()));
    d->changeHp(dmg); 
    if(d->getHp()<=0){
            throw Attack{dmg, 0, Result::death};
    } else {
      throw Attack{dmg, d->getHp(), Result::attack};
    }    
  } else {
    throw Attack{0, d->getHp(), Result::miss};
  }
}

