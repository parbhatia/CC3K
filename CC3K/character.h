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
    int missChance;
  public:
    Character(int atk, int def, int hp);
    void changeAtk(int n);
    void changeDef(int n);
    void changeHp(int n);
    void setMaxHp(int n);
    int getAtk();
    int getDef();
    int getHp();
    int getMaxHp();
    void attack(Item *whoTo) override;
    void attack(Character *whoTo) override;
    void beUsed(Player *whoFrom);
    void beAttacked(Object *whoFrom) override;
    ~Character() = 0;
};
#endif
