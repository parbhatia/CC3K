#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy : public Character {
    bool isHostile;
public:
    Enemy(double atk, double def, double hp);
    ~Enemy() = 0;
    
};

#endif
