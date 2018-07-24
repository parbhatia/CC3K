#include "troll.h"
#include "halfling.h"
#include "dwarf.h"
#include "attack.h"
#include <cstdlib>

Troll::Troll(double atk, double def, double hp): Player{atk, def, hp} {}

void Troll::beAttacked(Object *whoFrom) {
  whoFrom->attack(this);
}

void Troll::attack(Halfling *h) {
  int chance = rand() % 10 + 1;
  if (chance > 5) {   // Halfling has 50% chance to cause PC to miss.
    double dmg = (-getAtk() * 100 / (100 + h->getDef()));
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
void Troll::attack(Dwarf *d) {
  double chance = rand() % 10 + 1;
  if (chance > getMissChance()) {
    double dmg = (-getAtk() * 100 / (100 + d->getDef()));
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

