#ifndef potion_hpp
#define potion_hpp
#include "item.h"


class Potion : public Item{
public:
    ~Potion() = 0;
    char print() override;
};

#endif
