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

class Grid {
    int width = 79;
    int height = 30;
    std::vector<std::vector<Cell *>> cells;
    int level = 1;
    std::string race;
    int gold = 0;
    Object *player = nullptr; //grid keeps track of player
    Cell *player_cell = nullptr; //keeping track of player's movements
    std::vector<Chamber> chambers; //chambers on each level
    std::vector<std::string> actions; //keeping track of actions
    bool in_range(int row, int col); //returns true if row,col is in range of grid

  public:
    Grid();
    ~Grid();
    void new_level();
    void reset_cell();
    void read_layout(std::string s);
    bool has_player_test(); //delete later
    void cell_test(); //delete later
    void intialize_player(std::string type); //initializes player with race type, and changes race attribute for display purposes
    void default_layout();
    void move_player(Direction d);    //moves player in d
    void move_enemies(); //moves all enemies in random directions
    void use_pot(Direction d); //makes player use potion in d
    void generate_enemies(); //chambers generate enemies
    void generate_stairs(); //random chamber generates stairs
    void create_randomness(); //sets time as seed 
    int chamber_picker(); //returns random chamber (0 to 4)
    void test_chambers();    //for testing chambers, delete later!
    void reset_chambers();   //regenerates all chambers
    void set_observers();    //sets observers for cell
    bool valid_direction();
    void update_observers();
    friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
