#ifndef halfling_hpp
#define halfling_hpp
#include <iostream>
#include "enemy.h"
class Object;

class Halfling : public Enemy
{
  public:
    Halfling();
    void beAttacked(Object* whoFrom) override;
    char print() override;
    void attack(Goblin* g) override;
    void attack(Drow *h) override;
    
};

#endif
