#include "doorcell.h"
#include <string>


DoorCell::DoorCell(int r, int c) :  Cell{r,c} {} 

char DoorCell::print() {
        return '+';
}

DoorCell::~DoorCell() {}

int DoorCell::acceptMove(Cell &whoFrom) {
    std::cout << "DOOR ACEPTING MOVE" << std::endl;
    if (!isOccupied()) {
        setPlayer(whoFrom.getPlayer());
        return 2;
    } else {
        return 0;
    }
}
