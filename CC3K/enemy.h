#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy : public Character {
    bool isHostile;
public:
    Enemy(int atk, int def, int hp);
    void attack(Character* whoTo) override;

    
};

#endif
