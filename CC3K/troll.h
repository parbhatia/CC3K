#ifndef TROLL_H
#define TROLL_H
#include "player.h"
#include <string>

class Troll: public Player
{
  public:
    Troll(double atk = 25, double def = 15, double hp = 120);
    void beAttacked(Object *whoFrom) override;
    void attack(Halfling *h) override;
    void attack(Dwarf *d) override;
};
#endif
