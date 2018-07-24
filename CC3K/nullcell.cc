#include "nullcell.h"

NullCell::NullCell(int r, int c, char t):Cell{r,c,t} {}

void NullCell::moveTo(Cell &whoTo) { throw Move_Unsuccessful(); }

void NullCell::acceptMove(Cell &whoFrom) { throw Move_Unsuccessful(); }

NullCell::~NullCell() {}
