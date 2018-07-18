#include <vector>
#include "cell.h"

class Chamber{
    std::vector<Cell*> cells;
    static int numPotions, numGold, numEnemies;
public:
    void print();
    void generate_potion();
    void generate_gold();
    void generate_enemy();
    void reset();
    void add_cell(Cell *c);
};


