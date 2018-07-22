#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "player.h"
#include <string>


class Vampire: public Player {
public:
    Vampire(int atk=25, int def=25, int hp=50);
    //char print() override;
    void beAttacked(Object *whoFrom) override;
};
#endif
