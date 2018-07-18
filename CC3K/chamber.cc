#include "chamber.h"

void Chamber::reset(){
    for(auto cell:cells){
        cell->clear();
    }
}

void Chamber::generate_potion(){}