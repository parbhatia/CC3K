#include "character.h"
#include <cstdlib>
#include <ctime>
    
Character::Character(int atk, int def, int hp) : atk{atk}, def{def}, hp{hp}, maxHp{hp}, missChance{0} {}
void Character::changeAtk(int n) {
    atk += n;
}
void Character::changeDef(int n) {
    def += n;
}
void Character::changeHp(int n) {
    hp += n;  
}
void Character::setMaxHp(int n) {maxHp = n;}
int Character::getAtk() {return atk;}
int Character::getDef() {return def;}
int Character::getHp() {return hp;}
int Character::getMaxHp() {return maxHp;}
int Character::getMissChance() {return missChance;}
void Character::attack(Item *whoTo) {} //Attack an item is not a valid command, so it does nothing.
void Character::attack(Character *whoTo) {
    int chance = rand()%10 + 1;
    if (chance > missChance) {
        whoTo->changeHp(-getAtk()*100/(100+whoTo->getDef())); 
    }
}
void Character::beUsed(Player *whoFrom) {}; //Only a potion can be used or a gold can be picked, so it does nothing.ss

void Character::beAttacked(Object *whoFrom) {}

Character::~Character() {}
