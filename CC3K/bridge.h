#ifndef bridge_hpp
#define bridge_hpp
#include "cell.h"

class Object;
class Bridge: public Cell{
public:
    Bridge(int r, int c, char t);
    ~Bridge() {}
//    void move_to(Cell& to) override;
//    bool accept_move(Cell &who) override;
//    void attack(Cell &target) override;
//    void beAttacked(Cell &whoFrom) override;
//    
//    void notifyObservers() override;
//    void notify(Cell &whoFrom) override;
//    Object& getObject() override;
//    void attachObserver(Cell* ob) override;
};

#endif
