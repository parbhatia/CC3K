#ifndef doorcell_hpp
#define doorcell_hpp
#include "cell.h"

class Object;

class DoorCell : public Cell {
public:
    DoorCell(int r, int c);
    char print() override;
    ~DoorCell();
    /*
    void move_to(Cell& to) override;
    bool accept_move(Cell &who) override;
    void attack(Cell &target) override;
    void beAttacked(Cell &whoFrom) override;
    
    void notifyObservers() override;
    void notify(Cell &whoFrom) override;
    Object& getObject() override;
    void attachObserver(Cell* ob) override;
    */
};

#endif
