#include "human.h"

char Human::print(){
    return 'H';
}

Human::Human() : Enemy{20, 20, 140} {}

void Human::beAttacked(Object* whoFrom){
    whoFrom->attack(this);
}