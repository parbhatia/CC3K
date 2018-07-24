#ifndef nullcell_hpp
#define nullcell_hpp
#include "cell.h"

class Object;
class NullCell: public Cell{
    char type;
public:
    NullCell(int r, int c, char type);

    ~NullCell();
    void moveTo(Cell &whoTo) override;
    void acceptMove(Cell &whoFrom) override;
};

#endif
