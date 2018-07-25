#include "bridge.h"
Bridge::Bridge(int r, int c, char t): Cell(r, c, t){}

void Bridge::acceptMove(Cell &whoFrom) {
    if (whoFrom.hasObject()) throw Move_Unsuccessful();
    else Cell::acceptMove(whoFrom);
}

bool Bridge::canDragon() { return false; }
