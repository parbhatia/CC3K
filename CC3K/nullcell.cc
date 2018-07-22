#include "nullcell.h"

NullCell::NullCell(int r, int c, char type):Cell{r,c},type{type}{}


char NullCell::print(){
    return type;
}

bool NullCell::moveTo(Cell &whoTo) { return false; }

bool NullCell::acceptMove(Cell &whoFrom) { return false; }

NullCell::~NullCell() {}
