#include "dwarf.h"
#include "drow.h"
#include "goblin.h"
#include "attack.h"

Dwarf::Dwarf() : Enemy{20, 30, 100} {}

char Dwarf::print(){
    return 'W';
}

void Dwarf::beAttacked(Object* whoFrom) {
    whoFrom->attack(this);
}
