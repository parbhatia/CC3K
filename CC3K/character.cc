#include "character.h"
#include "attack.h" 
#include <cstdlib>
#include <ctime>
using namespace std;

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

void Character::addAction(std::string s) {
    actions.emplace_back(s);
}

void Character::cleanActions() {
    actions.clear();
}

std::string Character::storeAction(int dmg, char attacker, char defender, int hp){
    // char race = print();
    // stringstream ss;
    // ss << race << " deals " << std::to_string(dmg) << " to player.";
    // return ss.str();
    return;
}

std::string Character::getAction() { return actions[0]; }

void Character::attack(Item *whoTo) {} //Attack an item is not a valid command, so it does nothing.
void Character::attack(Character *whoTo) {
    int chance = rand() % 10 + 1;
    if (chance > whoTo->getMissChance()) {
        double dmg = (-getAtk() * 100 / (100 + whoTo->getDef()));
        whoTo->changeHp(dmg);
        stringstream ss;
        if(whoTo->getHp()<=0){
            ss << "PC kills " << whoTo->print() << ".";
            addAction(ss.str());
            //throw Attack{dmg, 0, Result::death};
        }
        else{
            // ss << printAttack(dmg);
            // addAction(ss.str());
            //throw Attack{dmg, whoTo->getHp(), Result::attack};
        } 
    } else {
       // throw Attack{0, whoTo->getHp(), Result::miss};
    }
}

void Character::beUsed(Player *whoFrom) {} //Only a potion can be used or a gold can be picked, so it does nothing.ss



Character::~Character() {}
