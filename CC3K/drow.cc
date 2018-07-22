#include "drow.h"

Drow::Drow(int atk, int def, int hp): Player{atk, def, hp} {}

void Drow::beAttacked(Object *whoFrom) {
  whoFrom->attack(this);
}