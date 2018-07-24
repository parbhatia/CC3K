#include "poiHP.h"
#include "player.h"
#include "attack.h"

void poiHP::beUsed(Player *whoFrom) {
    double before = whoFrom->getHp();
    if ((whoFrom->getHp() - 10 * whoFrom->getPotRate()) > 0) {
        whoFrom->changeHp(-10*whoFrom->getPotRate());
    } else {
        whoFrom->changeHp(0);
    }
    double after = whoFrom->getHp();
    throw Potion{before,after,Type::increaseHP};
}
poiHP::~poiHP(){}