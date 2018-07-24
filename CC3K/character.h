#ifndef CHARACTER_H
#define CHARACTER_H
#include "object.h"
#include <string>

class Character : public Object
{
    double atk;
    double def;
    double hp;
    double maxHp;
    int missChance;
    double potRate=1;
    double atkEffect=0;
    double defEffect=0; 
  public:
    Character(double atk, double def, double hp);
    void changeAtk(double n);
    void changeDef(double n);
    void changeHp(double n);
    void setMaxHp(double n);
    void setMissChance(int n);
    double getAtk();
    double getDef();
    double getHp();
    double getMaxHp();
    double getPotRate();
    int getMissChance();
    void setPotRate(double n);
    void resetEffect();
    void attack(Item *whoTo) override;
    void attack(Character *whoTo) override;
    void beUsed(Player *whoFrom) override;
    ~Character() = 0;
};
#endif
