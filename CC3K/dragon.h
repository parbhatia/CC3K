#ifndef DRAGON_H
#define DRAGON_H
#include "enemy.h"

class Dragon: public Enemy{
  public:
    Dragon();
    char print() override;
    void beAttacked(Object* whoFrom) override;
    void attack(Drow* d) override;
    void attack(Goblin* g) override;    
    void attack(Character* whoTo) override;
};


#endif