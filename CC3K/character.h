#ifndef CHARACTER_H
#define CHARACTER_H
#include "object.h"
#include <string>

class Character : public Object
{
    std::string race;
    int atk;
    int def;
    int hp;
  public:
    Character(std::string race, int atk, int def, int hp) : race{race}, atk{atk}, hp{hp} {}
    void changeAtk(int n) {
      atk += n;
    }
    void changeDef(int n) {
      def += n;
    }
    void changeHp(int n) {
      hp += n;  
    }
    int getAtk() {return atk;}
    int getDef() {return def;}
    int getHp() {return hp;}
    void beAttacked(Object *whoFrom) override { 
        whoFrom->attack(this);
    }
    void attack(Item *whoTo) override{} //Attack an item is not a valid command, so it does nothing.
    void attack(Character *whoTo) override {
        whoTo->changeHp(getAtk() - whoTo->getDef());
    }
    void beUsed(Player *whoFrom) override{}; //Only a potion can be used or a gold can be picked, so it does nothing.
};
#endif
