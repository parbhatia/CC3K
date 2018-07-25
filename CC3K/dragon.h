#ifndef DRAGON_H
#define DRAGON_H
#include "enemy.h"

class Dragon: public Enemy{
    bool dragon_hostile = false;
  public:
    Dragon();
    char print() override;
    void beAttacked(Object* whoFrom) override;
    /*void attack(Drow* d) override;
    void attack(Goblin* g) override;    
    void attack(Character* whoTo) override;*/
    bool getHostile()override;
    void setHostile(bool n=true) override;
};


#endif