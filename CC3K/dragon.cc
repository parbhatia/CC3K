#include "dragon.h"
#include "drow.h"
#include "goblin.h"
#include "attack.h"

Dragon::Dragon(): Enemy{20, 20, 150} {}
char Dragon::print() {
    return 'D';
} 
void Dragon::beAttacked(Object* whoFrom) {
    whoFrom->attack(this);
}

void Dragon::setHostile(bool n) {
    dragon_hostile = n;
}

void Dragon::setDGold(Object* g) {
    dgold = g;
}

Object* Dragon::getDGold() {
    return dgold;
}
bool Dragon::getHostile() {
    return dragon_hostile;
}

