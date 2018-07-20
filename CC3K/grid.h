#ifndef grid_hpp
#define grid_hpp
#include <iostream>
#include <vector>
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
    std::string race = "Shade";
    Cell *player_cell = nullptr;
    //Character *player = nullptr;
    std::vector<Chamber> chambers;
    bool in_range(int row, int col); //returns true if row,col is in range of grid

  public:
    Grid();
    //~Grid();
    void read_layout(std::string s);
    void intialize_player(std::string type); //initializes player with race type, and changes race attribute for display purposes
    void default_layout();
    //void move_player(Direction d);    //moves player in d
    //void use_pot_player(Direction d); //makes player use potion in d
    void generate_enemies(); //chambers generate enemies
    void test_chambers();    //for testing chambers, delete later!
    void reset_chambers();   //regenerates all chambers
    void set_observers();    //sets observers for cell
    bool valid_direction();
    void update_observers();
    friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
