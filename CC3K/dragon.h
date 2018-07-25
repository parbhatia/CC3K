#ifndef DRAGON_H
#define DRAGON_H
#include "enemy.h"
#include "gold.h"

class Dragon: public Enemy{
    bool dragon_hostile = false;
    Gold* dragongold = nullptr;
  public:
    Dragon();
    void setDragongold(Gold* g);
    Gold* getDragongold();
    char print() override;
    void beAttacked(Object* whoFrom) override;
    /*void attack(Drow* d) override;
    void attack(Goblin* g) override;    
    void attack(Character* whoTo) override;*/
    bool getHostile()override;
    void setHostile(bool n=true) override;
};


#endif