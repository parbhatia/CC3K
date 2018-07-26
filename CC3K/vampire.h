#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "player.h"
#include <string>


class Vampire: public Player {
public:
    Vampire(double atk=25, double def=25, double hp=50);
    void beAttacked(Object *whoFrom) override;
    void attack(Enemy *whoTo) override; //gains 5 hp every successful attack
    void attack(Halfling *h) override;
    void attack(Dwarf *d) override;
};
#endif
