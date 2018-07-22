#ifndef nullcell_hpp
#define nullcell_hpp
#include "cell.h"

class Object;
class NullCell: public Cell{
    char type;
public:
    NullCell(int r, int c, char type);

    char print() override;
    ~NullCell();
    int moveTo(Cell &whoTo) override;
    int acceptMove(Cell &whoFrom) override;
    
//    void attack(Cell &target) override;
//    void beAttacked(Cell &whoFrom) override;
//
//    void notifyObservers() override;
//    void notify(Cell &whoFrom) override;
//    Object& getObject() override;
//    void attachObserver(Cell* ob) override;
};

#endif
