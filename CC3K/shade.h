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
    Shade(double atk = 25, double def = 25, double hp = 125);
    void beAttacked(Object *whoFrom) override;
};
#endif
