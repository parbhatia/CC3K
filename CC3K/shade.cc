#include "shade.h"

Shade::Shade(int atk, int def, int hp): Player{atk, def, hp} {}

void Shade::beAttacked(Object *whoFrom) {
  whoFrom->attack(this);
}

char Shade::print() {
    return 'S';
}
