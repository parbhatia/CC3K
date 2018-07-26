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

