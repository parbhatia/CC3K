#ifndef potion_hpp
#define potion_hpp
#include "item.h"

class Potion:public Item{
    ~Potion() = 0;
    char print() override;
};

#endif
