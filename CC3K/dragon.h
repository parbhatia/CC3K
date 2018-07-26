#ifndef DRAGON_H
#define DRAGON_H
#include "enemy.h"
#include "gold.h"

class Dragon: public Enemy{
    bool dragon_hostile = false;
    Object* dgold = nullptr;
  public:
    Dragon();
    void setDGold(Object* g) override;
    Object* getDGold() override;
    char print() override;
    void beAttacked(Object* whoFrom) override;
    bool getHostile()override;
    void setHostile(bool n=true) override;
};


#endif
