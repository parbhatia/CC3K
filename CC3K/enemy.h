#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy : public Character {
    bool isHostile = true;
public:
    Enemy(double atk, double def, double hp);
    ~Enemy() = 0;
    void setHostile(bool n);
    bool getHostile();
    void notify(Player* p) override;
};

#endif
