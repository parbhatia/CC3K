#ifndef human_hpp
#define human_hpp
#include <iostream>
#include "enemy.h"
class Object;

class Human : public Enemy
{
  public:
    Human();
    char print() override;
    void beAttacked(Object* whoFrom) override;
};

#endif
