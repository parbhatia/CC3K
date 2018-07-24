#include "minAtk.h"
#include "player.h"
#include "attack.h"

void MinAttack::beUsed(Player *whoFrom){
    double before = whoFrom->getAtk();
    whoFrom->changeAtk(-5*whoFrom->getPotRate());
    double after = whoFrom->getAtk();
    throw Potion{before,after,Type::decreaseATK};
}

MinAttack::~MinAttack(){}
