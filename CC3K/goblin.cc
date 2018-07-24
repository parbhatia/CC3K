#include "goblin.h"
#include "halfling.h"
#include "dwarf.h"
#include "attack.h"
#include <cstdlib>

Goblin::Goblin(): Player{15, 20, 110} {}

void Goblin::beAttacked(Object *whoFrom) {
  whoFrom->attack(this);
}

void Goblin::attack(Character *whoTo) {
    int chance = rand() % 10 + 1;
    if (chance > getMissChance()) {
        double dmg = (-getAtk() * 100 / (100 + whoTo->getDef()));
        whoTo->changeHp(dmg);
        if (whoTo->getHp() <= 0) {
          changeGold(5); //Goblin steals 5 gold from every slain enemy.
          throw Attack{dmg, 0 , Result::death};
        } else {
          throw Attack{dmg, whoTo->getHp(), Result::attack};
        } 
    } else {
          throw Attack{0, whoTo->getHp(), Result::miss};
    }
}

void Goblin::attack(Halfling *h) {
  int chance = rand() % 10 + 1;
  if (chance > 5) {   // Halfling has 50% chance to cause PC to miss.
    double dmg = (-getAtk() * 100 / (100 + h->getDef()));
    h->changeHp(dmg);
    if (h->getHp() <= 0) {
      changeGold(5); //Goblin steals 5 gold from every slain enemy.
      throw Attack{dmg, 0, Result::death};
    } else {
      throw Attack{dmg, h->getHp(), Result::attack};
    } 
  } else {
      throw Attack{0, h->getHp(), Result::miss};
  } 
}

void Goblin::attack(Dwarf *d) {
  int chance = rand() % 10 + 1;
  if (chance > getMissChance()) {
    double dmg = (-getAtk() * 100 / (100 + d->getDef()));
    d->changeHp(dmg);
    if (d->getHp() <= 0) {
      changeGold(5); //Goblin steals 5 gold from every slain enemy.
      throw Attack{dmg, 0, Result::death};
    } else {
      throw Attack{dmg, d->getHp(), Result::attack};
    }
  } else {
     throw Attack{0, d->getHp(), Result::miss};
  }
}


