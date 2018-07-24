#include "plusAtk.h"
#include "player.h"

void PlusAttack::beUsed(Player *whoFrom){
    whoFrom->changeAtk(5*whoFrom->getPotRate());
}

PlusAttack::~PlusAttack(){}
