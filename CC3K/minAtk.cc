#include "minAtk.h"
#include "player.h"

void MinAttack::beUsed(Player *whoFrom){
    whoFrom->changeAtk(-5*whoFrom->getPotRate());
}

MinAttack::~MinAttack(){}
