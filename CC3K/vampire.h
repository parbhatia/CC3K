#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "player.h"
#include <string>


class Vampire: public Player {
public:
    Vampire(std::string race="Vampire", int atk=25, int def=25, int hp=50): Player{race, atk, def, hp} {}
    char print() override;
    void acceptattack(Object *whoFrom) override;
    void attack(Character *whoTo) override;
    void attack(Item *whoTo) override;
    void attack(Halfling* h) override;
    void attack(Dwarf* d) override;
    void attack(Drow* h) override;
    void attack(Goblin* g) override;
};
#endif