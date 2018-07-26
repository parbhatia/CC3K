#ifndef item_hpp
#define item_hpp
#include <iostream>
#include "object.h"

class Item: public Object{
public:
    void beAttacked(Object *whoFrom) override;
    void attack(Item *whoTo) override;
    void notify(Player* p) override;
    ~Item();
};




#endif
