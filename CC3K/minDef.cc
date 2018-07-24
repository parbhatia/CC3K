#include "minDef.h"
#include "player.h"

void MinDef::beUsed(Player *whoFrom){
    whoFrom->changeDef(-5*whoFrom->getPotRate());
}

MinDef::~MinDef(){}
