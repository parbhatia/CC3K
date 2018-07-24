#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"
#include <string>

class Player : public Character {
    int gold;
    bool merchant_hostile;
public:
    Player( double atk, double def, double hp);
    char print() override;
    void changeGold(int n);
    int getGold();
    void notify(Player* p) override;
};
#endif
