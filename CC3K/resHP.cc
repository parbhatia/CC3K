#include "resHP.h"
#include "player.h"
#include "attack.h"
#include <iostream>
using namespace std;

void resHP::beUsed(Player *whoFrom) {
    double before = whoFrom->getHp();
    cout << before << endl;
    if ((whoFrom->getHp() + 10 * whoFrom->getPotRate()) <= whoFrom->getMaxHp()) {
        whoFrom->changeHp(10*whoFrom->getPotRate());
        cout << "here" << endl;
    } else {
        whoFrom->changeHp(whoFrom->getMaxHp() - whoFrom->getHp());
        cout << "here2" << endl;
    }
    double after = whoFrom->getHp();
    cout << "here3" << endl;
    throw Poteffect{before, after, Type::increaseHP};
}
resHP::~resHP(){}
