#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "player.h"
#include <string>


class Vampire: public Player {
public:
    Vampire(int atk=25, int def=25, int hp=50);
    void beAttacked(Object *whoFrom) override;
    void attack(Character *whoTo) override; //gains 5 hp every successful attack
    void attack(Halfling *h) override;
    void attack(Dwarf *d) override;
};
#endif
