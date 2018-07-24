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
  public:
    void print();
    //void generate_potion();
    //void generate_gold();
    void generate_enemy();
    void clear(); //clear stats for new level
    int cell_picker(); //picks random cell
    int enemy_picker(); //picks random enemy type(int)
    void generate_player(std::string type);
    void generate_stairs();
    void generate_player_cell(Player *p); //puts Player on existing cell
    Cell *give_playercell(); //gives player cell to Grid, assumes chamber has player
    Player *give_player(); //gives player to Grid, assumes chamber has a player cell
    void reset();
    void add_cell(Cell *c);
};

#endif
