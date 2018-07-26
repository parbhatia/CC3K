#include "merchant.h"
#include "drow.h"
#include "goblin.h"
#include "attack.h"
#include "gold.h"

Merchant::Merchant(): Enemy{70, 5, 30} {}
char Merchant::print() {
    return 'M';
} 
void Merchant::beAttacked(Object* whoFrom) {
    whoFrom->attack(this);
}

bool Merchant::getHostile() {
    return merchant_hostile;
}
void Merchant::setHostile(bool n) {
    merchant_hostile = n;
}

void Merchant::resetHostile() {
    merchant_hostile = false;
}

Object* Merchant::spawn() {
    return new Gold{4};
}