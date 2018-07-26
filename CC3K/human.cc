#include "human.h"
#include "attack.h"
#include "goblin.h"
#include "drow.h"
#include "gold.h"
char Human::print(){
    return 'H';
}

Human::Human() : Enemy{20, 20, 140} {}

void Human::beAttacked(Object* whoFrom){
    whoFrom->attack(this);
}

Object* Human::spawn() {
    return new Gold{2};
}
