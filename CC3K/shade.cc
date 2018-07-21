#include "shade.h"

Shade::Shade(int atk, int def, int hp) : Player{atk, def, hp} {}

char Shade::print() {
    return 'S';
}
