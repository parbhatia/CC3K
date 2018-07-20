#ifndef CHARACTER_H
#define CHARACTER_H
#include "object.h"
#include <string>

class Character : public Object
{
    int atk;
    int def;
    int hp;
  public:
    Character(int atk, int def, int hp) : atk{atk}, def{def}, hp{hp} {}
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
