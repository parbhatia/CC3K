#include "troll.h"
#include "halfling.h"
Troll::Troll(int atk, int def, int hp): Player{atk, def, hp} {}

void Troll::beAttacked(Object *whoFrom) {
  whoFrom->attack(this);
}
/*void Shade::attack(Halfling *h);
void attack(Dwarf *d);
void attack(Drow *h);
void attack(Goblin *g);*/
