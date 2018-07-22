#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "player.h"
#include <string>


class Vampire: public Player {
public:
    Vampire(int atk=25, int def=25, int hp=50): Player{atk, def, hp} {}
    char print() override { return 'V';}
    void beAttacked(Object *whoFrom) override {
      whoFrom->attack(this);
    }
};
#endif