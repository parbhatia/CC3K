#ifndef bridge_hpp
#define bridge_hpp
#include "cell.h"

class Object;
class Bridge: public Cell{
public:
    Bridge(int r, int c, char t);
    void acceptMove(Cell &whoFrom) override;
    bool canDragon() override;
    ~Bridge() {}
};

#endif
