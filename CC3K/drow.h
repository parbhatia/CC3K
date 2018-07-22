#ifndef DROW_H
#define DROW_H
#include "player.h"
#include <string>


class Drow: public Player {
public:
    Drow(int atk=25, int def=15, int hp=150);
    char print() override;
    void beAttacked(Object *whoFrom) override;
};
#endif