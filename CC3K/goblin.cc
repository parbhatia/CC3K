#include "goblin.h"

Goblin::Goblin(): Player{15, 20, 110} {}

void Goblin::beAttacked(Object *whoFrom) {
  whoFrom->attack(this);
}