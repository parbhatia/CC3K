#include <vector>
#include "cell.h"
#include "shade.h"
#include "info.h"
#include "factory.h"

class Chamber {
    std::vector<Cell *> cells;
    static int numPotions, numGold, numEnemies;
    Factory f;
  public:
    void print();
    //void generate_potion();
    //void generate_gold();
    void generate_enemy();
    int cell_picker(); //picks random cell
    int enemy_picker(); //picks random enemy type(int)
    void generate_player(std::string type);
    void reset();
    void add_cell(Cell *c);
};
