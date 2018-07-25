#include "item.h"

//char Item::print(){}
void Item::attack(Item *whoTo){} // item cannot attack nor be attacked.
//void Item::beUsed(Player *whoFrom){}
void Item::beAttacked(Object *whoFrom){}
void Item::notify(Player* p) {}
Item::~Item(){}
