#ifndef SHADE_H
#define SHADE_H
#include "player.h"
#include <string>

class Shade : public Player
{
  public:
    Shade(std::string race = "Shade", int atk = 25, int def = 25, int hp = 125) : Player{race, atk, def, hp} {}
    char print() override;
};
#endif