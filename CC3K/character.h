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
};
#endif
