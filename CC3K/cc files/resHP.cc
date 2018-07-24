#include "resHP.h"
void resHP::beUsed(Player *whoFrom) {
    if ((whoFrom->getHp() + 10 * whoFrom->getPotRate()) <= whoFrom->getMaxHp()) {
        whoFrom->changeHp(10*whoFrom->getPotRate());
    } else {
        whoFrom->changeHp(whoFrom->getMaxHp() - whoFrom->getHp());
    }
}
