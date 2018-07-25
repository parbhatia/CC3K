#ifndef SHADE_H
#define SHADE_H
#include "player.h"
#include <string>
#include <sstream>

class Halfling;
class Dwarf;
class Shade : public Player
{
  public:
    Shade(double atk = 50, double def = 999, double hp = 999);
    void beAttacked(Object *whoFrom) override;
    /*void attack(Halfling *h) override;
    void attack(Dwarf *d) override;*/
};
#endif
