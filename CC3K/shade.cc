#include "shade.h"
Shade::Shade(int atk = 25, int def = 25, int hp = 125): Player{atk, def, hp} {}
char Shade::print() {
    return 'S';
}
void Shade::beAttacked(Object *whoFrom) {
  whoFrom->attack(this);
}