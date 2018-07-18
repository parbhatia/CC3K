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
};
#endif
