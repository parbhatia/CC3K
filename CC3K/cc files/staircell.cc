#include "staircell.h"


StairCell::StairCell(int r, int c) :  Cell{r,c} {}

char StairCell::print() {
    return '/';
}

StairCell::StairCell() {}

int StairCell::acceptMove(Cell &whoFrom) {
    if (!isOccupied()) {
        setPlayer(whoFrom.getPlayer());
        return 3;
    } else {
        return 0;
    }
}

bool StairCell::isOccupied() override { return true; }
