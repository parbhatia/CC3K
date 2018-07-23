#include "nullcell.h"

NullCell::NullCell(int r, int c, char type):Cell{r,c},type{type}{}


char NullCell::print(){
    return type;
}

int NullCell::moveTo(Cell &whoTo) { return 0; }

int NullCell::acceptMove(Cell &whoFrom) { return 0; }

NullCell::~NullCell() {}
