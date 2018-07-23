#ifndef GOBLIN_H
#define GOBLIN_H
#include "player.h"

class Goblin : public Player
{
  public:
    Goblin();
    void beAttacked(Object *whoFrom) override;
    void attack(Halfling *h) override;
    void attack(Dwarf *d) override;
};

#endif
