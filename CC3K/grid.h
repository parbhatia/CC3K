#ifndef grid_hpp
#define grid_hpp
#include <iostream>
#include <vector>
#include <string>
#include "cell.h"
#include <iomanip>
#include "doorcell.h"
#include "floorcell.h"
#include "nullcell.h"
#include "bridge.h"
#include "chamber.h"
#include "character.h"
#include "info.h"
#include "player.h"
#include "attack.h"

class Grid {
    int width = 79;
    int height = 30;
    std::vector<std::vector<Cell *>> cells;
    int level = 1;
    std::string race;
    int gold = 0;
    Player *player = nullptr; //grid keeps track of player
    Cell *player_cell = nullptr; //keeping track of player's movements
    std::vector<Chamber> chambers; //chambers on each level
    std::vector<std::string> actions; //keeping track of actions
    bool in_range(int row, int col); //returns true if row,col is in range of grid

  public:
    Grid();
    ~Grid();
    void new_level();
    void reset_cells();
    void reset_actions();
    void reset_chambers();
    void reset_cellsmoved(); //resets hasmoved flag on all cells
    void read_layout(std::string s);
    void attack_enemy(Direction d);
    void intialize_player(std::string type); //initializes player with race type, and changes race attribute for display purposes
    void default_layout();
    void move_player(Direction d);    //moves player in d
    void move_enemies(); //moves all enemies in random directions
    void use_pot(Direction d); //makes player use potion in d
    void generate_enemies(); //chambers generate enemies
    void generate_potions(); //chambers generate potions
    void generate_stairs(); //random chamber generates stairs
    void create_randomness(); //sets time as seed 
    int chamber_picker(); //returns random chamber (0 to 4)
    Direction direction_picker(); //returns random direction
    Cell* new_cell_pos(Cell *old_cell, Direction d); //returns new cell based on direction from old_cell
    void set_observers();    //sets observers for cell
    void test_observers();
    bool valid_direction();
    void notify_player_observers();
    friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
