#include "orc.h"

char Orc::print(){
    return 'O';
}

Orc::Orc() : Enemy{30, 25, 180} {
}

void Orc::beAttacked(Object* whoFrom){
    whoFrom->attack(this);
}

void Orc::attack(Goblin* g){

}