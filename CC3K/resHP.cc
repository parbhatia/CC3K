#include "resHP.h"
#include "player.h"
#include "attack.h"
#include <iostream>
using namespace std;

void resHP::beUsed(Player *whoFrom) {
    double before = whoFrom->getHp();
    if ((whoFrom->getHp() + 10 * whoFrom->getPotRate()) <= whoFrom->getMaxHp()) {
        whoFrom->changeHp(10*whoFrom->getPotRate());
    } else {
        whoFrom->changeHp(whoFrom->getMaxHp() - whoFrom->getHp());
    }
    double after = whoFrom->getHp();
    throw Poteffect{before, after, Type::increaseHP};
}
resHP::~resHP(){}
