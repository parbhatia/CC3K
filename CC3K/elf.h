#ifndef elf_hpp
#define elf_hpp
#include <iostream>
#include "enemy.h"
class Object;

class Elf : public Enemy
{
  public:
    Elf();
    char print() override;
    void beAttacked(Object* whoFrom) override;
    void attack(Drow* d) override;
    void attack(Character* whoTo) override;
};

#endif
