#ifndef CHARACTER_H
#define CHARACTER_H
#include "object.h"
#include <string>

class Character : public Object
{
    int atk;
    int def;
    int hp;
    int maxHp;
  public:
    Character(int atk, int def, int hp);
    void changeAtk(int n);
    void changeDef(int n);
    void changeHp(int n);
    int getAtk();
    int getDef();
    int getHp();
    void attack(Item *whoTo) override;
    void attack(Character *whoTo) override;
    void beUsed(Player *whoFrom);
};
#endif
