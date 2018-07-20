#ifndef SHADE_H
#define SHADE_H
#include "player.h"
#include <string>

class Shade : public Player
{
  public:
    Shade(std::string race = "Shade", int atk = 25, int def = 25, int hp = 125) : Player{race, atk, def, hp} {}
    char print() override;
    void beAttacked(Object *whoFrom) override;
    void attack(Item *whoTo) override;
    void attack(Character *whoTo) override;
    void attack(Halfling *h) override;
    void attack(Dwarf *d) override;
    void attack(Drow *h) override;
    void attack(Goblin *g) override;
};
#endif