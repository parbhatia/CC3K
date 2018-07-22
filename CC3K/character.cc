#include "character.h"
    
Character::Character(int atk, int def, int hp) : atk{atk}, def{def}, hp{hp}, maxHp{hp} {}
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
void Character::attack(Item *whoTo) {} //Attack an item is not a valid command, so it does nothing.
void Character::attack(Character *whoTo) {
    whoTo->changeHp(getAtk() - whoTo->getDef());
}
void Character::beUsed(Player *whoFrom) {}; //Only a potion can be used or a gold can be picked, so it does nothing.ss