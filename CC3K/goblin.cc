#include "goblin.h"
#include "halfling.h"
#include "dwarf.h"
#include "attack.h"
#include <cstdlib>

Goblin::Goblin(): Player{15, 20, 110} {}

void Goblin::beAttacked(Object *whoFrom) {
  whoFrom->attack(this);
}

void Goblin::attack(Enemy *whoTo) {
    double dmg = (-getAtk() * 100 / (100 + whoTo->getDef()));
    int chance = rand() % 10 + 1;
    if (chance > getMissChance()) {
        whoTo->changeHp(dmg);
        if (whoTo->getHp() <= 0) {
          changeGold(5); //Goblin steals 5 gold from every slain enemy.
          //throw Attack{dmg, 0 , Result::death};
        } else {

          //throw Attack{dmg, whoTo->getHp(), Result::attack};
        } 
    } else {
          dmg = 0;
    }
    Character::storeAction(dmg, print(), 'P', whoTo->getHp());
}

void Goblin::attack(Halfling *h) {
  double dmg = (-getAtk() * 100 / (100 + h->getDef()));
  int chance = rand() % 10 + 1;
  if (chance > 5) {   // Halfling has 50% chance to cause PC to miss.
    h->changeHp(dmg);
    if (h->getHp() <= 0) {
      changeGold(5); //Goblin steals 5 gold from every slain enemy.
    }
  }
  else {
      dmg = 0;
  } 
  Character::storeAction(dmg, print(), 'P', h->getHp());
}

void Goblin::attack(Dwarf *d) {
  double dmg = (-getAtk() * 100 / (100 + d->getDef()));
  int chance = rand() % 10 + 1;
  if (chance > getMissChance()) {
    d->changeHp(dmg);
    if (d->getHp() <= 0) {
      changeGold(5); //Goblin steals 5 gold from every slain enemy.
    }
  }
  else{
     dmg = 0;
  }
  Character::storeAction(dmg, print(), 'P', d->getHp());

}


