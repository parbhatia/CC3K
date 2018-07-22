#include "doorcell.h"
#include <string>


DoorCell::DoorCell(int r, int c) :  Cell{r,c} {} 

char DoorCell::print() {
        return '+';
}

DoorCell::~DoorCell() {}

//int DoorCell::moveTo(Cell& whoTo) { return 1; }

int DoorCell::acceptMove(Cell &whoFrom) {
    setPlayer(whoFrom.getPlayer());
    //notifyObservers();
    return 2;
}
