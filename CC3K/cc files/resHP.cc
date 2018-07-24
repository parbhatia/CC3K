#include "resHP.h"
void resHP::beUsed(Player *whoFrom) {
    if ((whoFrom->getHp() + 10) <= whoFrom->getMaxHp()) {
        whoFrom->changeHp(10);
    } else {
        whoFrom->changeHp(whoFrom->getMaxHp() - whoFrom->getHp());
    }
}
