#include "shade.h"
#include "halfling.h"
#include "dwarf.h"

#include <cstdlib>
using namespace std;

Shade::Shade(double atk, double def, double hp): Player{atk, def, hp} {}

void Shade::beAttacked(Object *whoFrom) {
    whoFrom->attack(this);
}
