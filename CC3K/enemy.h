#ifndef ENEMY_H
#define ENEMY_H

#include <sstream>
#include "character.h"

class Enemy : public Character {
public:
    Enemy(double atk, double def, double hp);
    ~Enemy() = 0;
    void notify(Player* p) override;
    void attack(Drow *d) override;
    void attack(Goblin *g) override;
};

#endif
