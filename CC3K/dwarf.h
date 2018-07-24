#ifndef dwarf_hpp
#define dwarf_hpp
#include <iostream>
#include "enemy.h"
class Object;

class Dwarf : public Enemy
{
  public:
    Dwarf();
    char print() override;
    void beAttacked(Object* whoFrom) override;
    void attack(Drow *d) override;
    void attack(Goblin *g) override;
};

#endif
