#ifndef orc_hpp
#define orc_hpp
#include "enemy.h"
class Object;

class Orc : public Enemy
{
  public:
    Orc();
    char print() override;
    void beAttacked(Object* whoFrom) override;   
    void attack(Goblin* g) override;
    void attack(Drow *h) override;
    ~Orc();
};

#endif
