#include "doorcell.h"
#include <string>

DoorCell::DoorCell(int r, int c, char t) :  Cell{r,c, t} {}

DoorCell::~DoorCell() {}

bool DoorCell::canDragon() { return false; }

/*void DoorCell::moveTo(Cell &whoTo) {
    //if (whoTo.hasObject())
    if (!has_moved() && !has_potion() && !has_gold()) {
        try {
            whoTo.acceptMove(*this);
        }
        catch(...) {
            //check that a player was trying to move
            //if it was, set whoFrom hasmoved to be true
            if (hasPlayer()) {
                set_moved();
            }
            throw;
        }
        //move was successful
        player = nullptr;
        ob = nullptr;
    }
}*/

void DoorCell::acceptMove(Cell &whoFrom) {
    if (whoFrom.hasObject()) throw Move_Unsuccessful();
    else Cell::acceptMove(whoFrom);
}

