#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"
#include <string>

class Player : public Character {
public:
    Player( int atk=10, int def=5, int hp=100): Character{atk, def, hp} {}
};
#endif
