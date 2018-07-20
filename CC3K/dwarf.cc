#include "dwarf.h"
void Dwarf::attack(Character *whoTo)
{
    whoTo->changeHp(whoTo->getHp() - getAtk() + whoTo->getDef);
}

void Dwarf::beAttacked(Object *whoFrom)
{
    whoFrom->attack(this);
}


char Dwarf::print(){
    return 'W';
}

