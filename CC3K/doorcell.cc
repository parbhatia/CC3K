#include "doorcell.h"
#include <string>


DoorCell::DoorCell(int r, int c) :  Cell{r,c} {} 

char DoorCell::print() {
        return '+';
}

DoorCell::~DoorCell() {}
/*

void DoorCell::move_to(Cell& to){}

bool DoorCell::accept_move(){
        //send player through the door
        //reject enemies
}



*/

