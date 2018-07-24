#include "plusAtk.h"
#include "player.h"
#include "attack.h"

void PlusAttack::beUsed(Player *whoFrom){
    double before = whoFrom->getAtk();
    whoFrom->changeAtk(5*whoFrom->getPotRate());
    double after = whoFrom->getAtk();
    throw Potion{before, after, Type::increaseATK};
}

PlusAttack::~PlusAttack(){}
