#ifndef bridge_hpp
#define bridge_hpp
#include "cell.h"

class Object;
class Bridge: public Cell{
public:
    Bridge(int r, int c);
    void move_to(Cell& to) override;
    bool accept_move(Cell &who) override;
    void interact(Cell &target) override;
    void accept_interact(Cell &whoFrom) override;
    char print() override;
    void notifyObservers() override;
    void notify(Cell &whoFrom) override;
    Object& getObject() override;
    void attachObserver(Cell* ob) override;
};

#endif