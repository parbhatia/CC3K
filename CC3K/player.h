#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"
#include <string>
#include <vector>

class Player : public Character {
    int gold;
    bool merchant_hostile;
    std::vector <std::string> actions;
public:
    Player( double atk, double def, double hp);
    char print() override;
    void changeGold(int n);
    int getGold();
    void addAction(std::string s);
    void cleanActions();
    void notify(Player* p) override;
};
#endif
