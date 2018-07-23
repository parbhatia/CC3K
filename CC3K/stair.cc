#include "stair.h"
#include <string>
using namespace std;

StairCell::StairCell(int r, int c) : Cell{r,c} {}

char StairCell::print() {
    return '/';
}

int StairCell::acceptMove(Cell &whoFrom) {
    if (!isOccupied()) {
        setPlayer(whoFrom.getPlayer());
        return 3;
    } else {
        return 0;
    }
}

//bool StairCell::isOccupied() { return true; }
