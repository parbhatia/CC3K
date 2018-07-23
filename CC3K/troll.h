#ifndef TROLL_H
#define TROLL_H
#include "player.h"
#include <string>

class Troll: public Player
{
  public:
    Troll(int atk = 25, int def = 15, int hp = 120);
    void beAttacked(Object *whoFrom) override;
    void attack(Halfling *h) override;
    void attack(Dwarf *d) override;
};
#endif
