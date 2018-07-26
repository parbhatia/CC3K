#include "doorcell.h"
#include <string>

DoorCell::DoorCell(int r, int c, char t) :  Cell{r,c, t} {}

DoorCell::~DoorCell() {}

bool DoorCell::canDragon() { return false; }

void DoorCell::acceptMove(Cell &whoFrom) {
    if (whoFrom.hasObject()) throw Move_Unsuccessful();
    else Cell::acceptMove(whoFrom);
}

