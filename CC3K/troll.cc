#include "troll.h"
#include "halfling.h"
#include "dwarf.h"

#include <cstdlib>

Troll::Troll(double atk, double def, double hp): Player{atk, def, hp} {}

void Troll::beAttacked(Object *whoFrom) {
  whoFrom->attack(this);
}

char Troll::print() {
  changeHp(5);
  return '@';
}
