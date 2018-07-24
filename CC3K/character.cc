#include "character.h"
#include "attack.h" 
#include <cstdlib>
#include <ctime>


Character::Character(double atk, double def, double hp) : atk{atk}, def{def}, hp{hp}, maxHp{hp}, missChance{0} {}
void Character::changeAtk(double n) {
    atkEffect += n;
}
void Character::changeDef(double n) {
    defEffect += n;
}
void Character::changeHp(double n) {
    hp += n;  
}
void Character::setMaxHp(double n) {
    maxHp = n;
}
void Character::setMissChance(int n) {   
    missChance = n;
}
void Character::resetEffect() {
    atkEffect = 0;
    defEffect = 0;
}
double Character::getAtk() {
    return atk + atkEffect;
}
double Character::getDef() {
    return def + defEffect;
}
double Character::getHp() {
    return hp;
}
double Character::getMaxHp() {
    return maxHp;
}
double Character::getPotRate() {
    return potRate;
}
int Character::getMissChance() {
    return missChance;
}
void Character::setPotRate(double n) {
    potRate = n;
}
void Character::attack(Item *whoTo) {} //Attack an item is not a valid command, so it does nothing.
void Character::attack(Character *whoTo) {
    int chance = rand() % 10 + 1;
    if (chance > whoTo->getMissChance()) {
        double dmg = (-getAtk() * 100 / (100 + whoTo->getDef()));
        whoTo->changeHp(dmg);
        if(whoTo->getHp()<=0){
            throw Attack{dmg, 0, Result::death};
        }
        else{
            throw Attack{dmg, whoTo->getHp(), Result::attack};
        } 
    } else {
        throw Attack{0, whoTo->getHp(), Result::miss};
    }
}

void Character::beUsed(Player *whoFrom) {} //Only a potion can be used or a gold can be picked, so it does nothing.ss

Character::~Character() {}
