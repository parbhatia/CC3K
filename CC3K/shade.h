#ifndef SHADE_H
#define SHADE_H
#include "player.h"
#include <string>

class Shade : public Player
{
  public:
    Shade(int atk = 25, int def = 25, int hp = 125): Player{atk, def, hp} {}
    char print() override {return 'S';}
    void beAttacked(Object *whoFrom) override {
      whoFrom->attack(this);
    }
};
#endif
