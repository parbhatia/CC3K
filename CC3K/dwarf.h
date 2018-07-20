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
};

#endif
