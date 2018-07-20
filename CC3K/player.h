#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"
#include <string>

class Player : public Character {
public:
    Player(std::string race="Shade", int atk=10, int def=5, int hp=100): Character{race, atk, def, hp} {}
    void beAttacked(Object *whoFrom) override { 
        whoFrom->attack(this);
    }
    void attack(Item *whoTo) override{} //Attack an item is not a valid command, so it does nothing.
    void attack(Character *whoTo) override {
        whoTo->changeHp(getAtk() - whoTo->getDef());
    }
    void beUsed(Player *whoFrom) {}; //Only a potion can be used or a gold can be picked, so it does nothing.
};
#endif
