#include "drow.h"
#include "halfling.h"
#include "dwarf.h"
#include "attack.h"
#include <cstdlib>

Drow::Drow(double atk, double def, double hp): Player{atk, def, hp} {
  setPotRate(1.5);
}

void Drow::beAttacked(Object *whoFrom) {
  whoFrom->attack(this);
}

void Drow::attack(Halfling *h) {
  int chance = rand() % 10 + 1;
  double dmg = (-getAtk() * 100 / (100 + h->getDef()));

  if (chance > 5) {   // Halfling has 50% chance to cause PC to miss.
    h->changeHp(dmg);
    if(h->getHp()<=0){
      throw Attack{dmg, 0, Result::death};
    }
  }
  else {
    dmg = 0;
  }
  Character::storeAction(dmg, 'P', h->print(), h->getHp);

}

void Drow::attack(Dwarf *d) {
  int chance = rand() % 10 + 1;
  double dmg = (-getAtk() * 100 / (100 + d->getDef()));

  if (chance > getMissChance()) {
    d->changeHp(dmg); 
    if(d->getHp()<=0){
            throw Attack{dmg, 0, Result::death};
    }
  }
  else {
    dmg = 0;
  }
  
}

