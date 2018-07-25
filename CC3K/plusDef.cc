#include "plusDef.h"
#include "player.h"

void PlusDef::beUsed(Player *whoFrom){
    whoFrom->changeDef(5*whoFrom->getPotRate());
    Character::storePotion("BD");
}

PlusDef::~PlusDef(){}
