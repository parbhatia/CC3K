#ifndef dwarf_hpp
#define dwarf_hpp
#include <iostream>
#include "enemy.h"
class Object;

class Dwarf: public Enemy {
public:
    void interact(Character *whoTo) override;
    void acceptInteract(Object *whofrom) override;
    char print() override;
};


#endif
