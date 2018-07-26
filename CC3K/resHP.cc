#include "resHP.h"
#include "player.h"

#include <iostream>
using namespace std;

void resHP::beUsed(Player *whoFrom) {
    if ((whoFrom->getHp() + 10 * whoFrom->getPotRate()) <= whoFrom->getMaxHp()) {
        whoFrom->changeHp(10*whoFrom->getPotRate());
    } else {
        whoFrom->changeHp(whoFrom->getMaxHp() - whoFrom->getHp());
    }
    Character::storePotion("RH");
}
resHP::~resHP(){}
