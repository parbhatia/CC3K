#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"
#include <string>

class Player : public Character {
    int gold;
    bool merchant_hostile;
public:
    Player( int atk=10, int def=5, int hp=100): Character{atk, def, hp}, gold{0}, merchant_hostile(false) {}
};
#endif
