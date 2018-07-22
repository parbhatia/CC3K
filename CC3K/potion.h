#ifndef potion_hpp
#define potion_hpp
#include "item.h"


class Potion : public Item{
public:
    ~Potion();
    char print() override;
//    void beAttacked(Object *whoFrom) override;
//    void attack(Item *whoTo) override;
//    void attack(Character *whoTo) override;
};

#endif
