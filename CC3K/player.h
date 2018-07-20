#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"
#include <string>

class Player : public Character {
public:
    Player(std::string race, int atk, int def, int hp): Character{race, atk, def, hp} {}
};
#endif
