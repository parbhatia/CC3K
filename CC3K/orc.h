#ifndef orc_hpp
#define orc_hpp
#include <iostream>
#include "enemy.h"
class Object;

class Orc : public Enemy
{
  public:
    Orc();
    char print() override;
};

#endif
