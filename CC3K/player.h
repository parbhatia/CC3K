#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"
#include <string>

class Player : public Character
{
public:
    Player(std::string race="Shade", int atk=10, int def=5, int hp=100): Character{race, atk, def, hp} {}
};
#endif