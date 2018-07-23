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
};

#endif
