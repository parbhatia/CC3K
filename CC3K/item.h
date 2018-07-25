#ifndef item_hpp
#define item_hpp
#include <iostream>
#include "object.h"

class Item: public Object{
public:
    //virtual char print();
    void beAttacked(Object *whoFrom) override;
    void attack(Item *whoTo) override;
    //virtual void beUsed(Player *whoFrom);  implement in concrete classes
    void notify(Player* p) override;
    ~Item();
};




#endif
