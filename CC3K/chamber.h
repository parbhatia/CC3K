#ifndef CHAMBER_H
#define CHAMBER_H

#include <vector>
#include "cell.h"
#include "shade.h"
#include "info.h"
#include "factory.h"

class Chamber {
    std::vector<Cell *> cells;
    static int numPotions, numGold, numEnemies;
    Factory f;
    Cell *player_cell = nullptr; //to give to Grid, gets nullpointed once it's called
  public:
    void print();
    //void generate_potion();
    //void generate_gold();
    void generate_enemy();
    int cell_picker(); //picks random cell
    int enemy_picker(); //picks random enemy type(int)
    void generate_player(std::string type);
    Cell *give_playercell(); //gives player cell to Grid
    void reset();
    void add_cell(Cell *c);
};

#endif
