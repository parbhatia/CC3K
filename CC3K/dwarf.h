#ifndef dwarf_hpp
#define dwarf_hpp
#include <iostream>
#include "enemy.h"
class Object;

class Dwarf : public Enemy
{
  public:
    void attack(Character *whoTo) override;
    void beAttacked(Object *whofrom) override;
    char print() override;
};

#endif
