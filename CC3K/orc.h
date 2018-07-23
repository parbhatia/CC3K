#ifndef orc_hpp
#define orc_hpp
#include <iostream>
#include "enemy.h"
class Object;

class Orc : public Enemy
{
  public:
    Orc();
    void beAttacked(Object* whoFrom) override;
    char print() override;
    void attack(Goblin* g) override;
};

#endif
