#ifndef stair_hpp
#define stair_hpp

#include "cell.h"

class Object;

class StairCell : public Cell {
public:
    StairCell(int r, int c);
    char print() override;
    ~StairCell() {}
    
    int acceptMove(Cell &whoFrom) override;
    //bool isOccupied();
    //    void attack(Cell &target) override;
    //    void beAttacked(Cell &whoFrom) override;
    //
    //    void notifyObservers() override;
    //    void notify(Cell &whoFrom) override;
    //    Object& getObject() override;
    //    void attachObserver(Cell* ob) override;
};

#endif
