#include "item.h"

//char Item::print(){}
void Item::attack(Item *whoTo){} // item cannot attack nor be attacked.
void Item::attack(Character *whoTo){}
void Item::beUsed(Player *whoFrom){}
void Item::beAttacked(Object *whoFrom){}
