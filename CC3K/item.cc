#include "item.h"

void Item::attack(Item *whoTo){} // item cannot attack nor be attacked.
void Item::beAttacked(Object *whoFrom){}
void Item::notify(Player* p) {}
Item::~Item(){}
