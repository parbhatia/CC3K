#include "dwarf.h"
void Dwarf::attack(Character *whoTo)
{
    whoTo->changeHp()
}

void Dwarf::beAttacked(Object *whoFrom)
{
    whoFrom->attack(this);
}