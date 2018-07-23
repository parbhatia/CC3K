#include "goblin.h"
#include "halfling.h"
#include "dwarf.h"
#include <ctime>
#include <cstdlib>

Goblin::Goblin(): Player{15, 20, 110} {}

void Goblin::beAttacked(Object *whoFrom) {
  whoFrom->attack(this);
}

void Goblin::attack(Character *whoTo) {
    int chance = rand() % 10 + 1;
    if (chance > getMissChance()) {
        whoTo->changeHp(-getAtk() * 100 / (100 + whoTo->getDef()));
        if (whoTo->getHp() < 0) {
          changeGold(5); //Goblin steals 5 gold from every slain enemy.
        } 
    }
}

void Goblin::attack(Halfling *h) {
  srand(time(NULL));
  int chance = rand() % 10 + 1;
  if (chance > 5) {   // Halfling has 50% chance to cause PC to miss.
    h->changeHp(-getAtk() * 100 / (100 + h->getDef()));
    if (h->getHp() < 0) {
      changeGold(5); //Goblin steals 5 gold from every slain enemy.
    } 
  }
}

void Goblin::attack(Dwarf *d) {
  srand(time(NULL));
  int chance = rand() % 10 + 1;
  if (chance > getMissChance()) {
    d->changeHp(-getAtk() * 100 / (100 + d->getDef()));
    if (d->getHp() < 0) {
      changeGold(5); //Goblin steals 5 gold from every slain enemy.
    } 
  }
}


