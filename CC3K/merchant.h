#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemy.h"

class Merchant: public Enemy{
    static bool merchant_hostile;
  public:
    Merchant();
    char print() override;
    void beAttacked(Object* whoFrom) override;
    /*void attack(Drow* d) override;
    void attack(Goblin* g) override;    
    void attack(Character* whoTo) override;*/
    bool getHostile() override;
    void setHostile(bool n=true) override;
    static void resetHostile();
};


#endif