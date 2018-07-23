#include "dwarf.h"


char Dwarf::print(){
    return 'W';
}

void Dwarf::beAttacked(Object* whoFrom) {
    whoFrom->attack(this);
}

Dwarf::Dwarf() : Enemy{20, 30, 100} {}