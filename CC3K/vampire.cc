#include "vampire.h"
#include <climits>

Vampire::Vampire(int atk, int def, int hp): Player{atk, def, hp} {
    setMaxHp(INT32_MAX);
}

char Vampire::print() {
     return 'V';
}

void Vampire::beAttacked(Object *whoFrom) {
  whoFrom->attack(this);
}
