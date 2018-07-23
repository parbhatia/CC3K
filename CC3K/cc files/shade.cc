#include "shade.h"
#include "halfling.h"
#include "dwarf.h"
#include "drow.h"
#include "goblin.h"


Shade::Shade(int atk, int def, int hp): Player{atk, def, hp} {}

void Shade::beAttacked(Object *whoFrom) {
  whoFrom->attack(this);
}
/*void Shade::attack(Halfling *h);
void attack(Dwarf *d);
void attack(Drow *h);
void attack(Goblin *g);*/

void Shade::attack(Halfling *h) {}
void Shade::attack(Dwarf *d) {}
