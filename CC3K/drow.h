#ifndef DROW_H
#define DROW_H
#include "player.h"

class Drow: public Player {
public:
    Drow(double atk=25, double def=15, double hp=150);
    void beAttacked(Object *whoFrom) override;
};
#endif
