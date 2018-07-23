#include "floorcell.h"

FloorCell::FloorCell(int r, int c): Cell{r,c} {  
}

char FloorCell::print(){
    if (player) return player->print();
    else if(ob){ return ob->print();}
    else return '.';
}
