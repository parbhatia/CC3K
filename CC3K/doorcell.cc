#include "doorcell.h"
#include <string>


DoorCell::DoorCell(int r, int c) :  Cell{r,c} {} 

char DoorCell::print() {
        return '+';
}
