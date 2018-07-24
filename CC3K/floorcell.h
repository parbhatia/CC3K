#ifndef floorcell_hpp
#define floorcell_hpp
#include "cell.h"

class Object;
class FloorCell: public Cell{
public:
    FloorCell(int r, int c, char t);

    ~FloorCell() {}
};

#endif
