#include "floorcell.h"

FloorCell::FloorCell(int r, int c): Cell{r,c} {  
}

char FloorCell::print(){
    if(ob){ return ' ';}
    else{
        return '.';
    }
}
