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
    if ( 0 <= hp + n && hp+n <= maxHp) {
        hp += n;
    } else if  (hp + n < 0) {
        hp = 0;
    } else {
        hp = maxHp;
    }  
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

bool Character::dead() { return hp <= 0; }

void Character::storeAction(int dmg, char attacker, char defender, int hp){
    stringstream ss;
    string a = (attacker=='@' || attacker=='P')?"PC":string(1,attacker);
    string d = (defender=='@' || defender=='P')?"PC":string(1,defender);
    if(hp>0){
        if(dmg){
            ss << a << " deals " << dmg << " damage to " << d << "(" << hp << " HP" << ").";
        }
        else{
            ss << a << " tries to attack " << d << " but misses!";
        }
        
    }
    else{
        ss << a << " deals " << dmg << " damage to " << d << ". " << d << " is defeated.";
    }
    Character::addAction(ss.str());

    
    // char race = print();
    // stringstream ss;
    // ss << race << " deals " << std::to_string(dmg) << " to player.";
    // return ss.str();
}

void Character::storePotion(std::string type){
    string s = "PC uses "+ type;
    Character::addAction(s);
}

void Character::clearActions() { actions.clear(); }

std::vector <std::string> Character::getAction() { return actions; }

void Character::attack(Item *whoTo) {} //Attack an item is not a valid command, so it does nothing.
/*void Character::attack(Character *whoTo) {
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
}*/

void Character::beUsed(Player *whoFrom) {} //Only a potion can be used or a gold can be picked, so it does nothing.ss



Character::~Character() {}
