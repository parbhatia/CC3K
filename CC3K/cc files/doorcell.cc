#include "doorcell.h"
#include <string>


DoorCell::DoorCell(int r, int c) :  Cell{r,c} {} 

char DoorCell::print() {
        return '+';
}

DoorCell::~DoorCell() {}

int DoorCell::acceptMove(Cell &whoFrom) {
    if (!isOccupied()) {
        setPlayer(whoFrom.getPlayer());
        return 2;
    } else {
        return 0;
    }
}
