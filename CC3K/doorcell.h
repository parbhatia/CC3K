#ifndef doorcell_hpp
#define doorcell_hpp
#include "cell.h"

class Object;

class DoorCell : public Cell {
public:
    DoorCell(int r, int c, char t);
    //void moveTo(Cell &whoTo);
    void acceptMove(Cell &whoFrom) override;
    ~DoorCell();
};

#endif
