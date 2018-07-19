#ifndef SHADE_H
#define SHADE_H
#include "player.h"
#include <string>


class Shade: public Player {
public:
    Shade(std::string race="Shade", int atk=10, int def=5, int hp=100): Player{race, atk, def, hp} {}
    char print() override;
    void acceptInteract(Object *whoFrom) override;
    void interact(Character *whoTo) override;
    void interact(Item *whoTo) override;
    void interact(Halfling* h) override;
    void interact(Dwarf* d) override;
    void interact(Drow* h) override;
    void interact(Goblin* g) override;
};
#endif