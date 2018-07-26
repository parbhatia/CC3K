#include "halfling.h"
#include "goblin.h"
#include "drow.h"

char Halfling::print(){
    return 'L';
}

Halfling::Halfling() : Enemy{15, 20, 100} {}

void Halfling::beAttacked(Object* whoFrom){
    whoFrom->attack(this);
}
