#include "troll.h"
#include "halfling.h"
Troll::Troll(int atk, int def, int hp): Player{atk, def, hp} {}

void Troll::beAttacked(Object *whoFrom) {
  whoFrom->attack(this);
}

void Troll::attack(Halfling *h) {}
void Troll::attack(Dwarf *d) {}
void Troll::attack(Drow *h) {}
void Troll::attack(Goblin *g) {}
