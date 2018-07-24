#include "minAtk.h"
#include "player.h"
#include "attack.h"

void MinAttack::beUsed(Player *whoFrom){
    double before = whoFrom->getAtk();
    whoFrom->changeAtk(-5*whoFrom->getPotRate());
    double after = whoFrom->getAtk();
    throw Poteffect{before,after,Type::decreaseATK};
}

MinAttack::~MinAttack(){}
