#include "nullcell.h"

NullCell::NullCell(int r, int c, char type):Cell{r,c},type{type}{}


char NullCell::print(){
    return type;
}
