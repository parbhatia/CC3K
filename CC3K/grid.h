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

using namespace std;

static int num_enemies = 20;
static int num_items = 20; //???

class Grid {
    int width = 79;
    int height = 30;
    std::vector <std::vector <Cell*>> cells;
    int level = 1;
    string race = "Shade";
    Character *player = nullptr;
    std::vector <Chamber> chambers;
public:
    Grid();
    //~Grid();
    void read_layout(string s);
    void intialize_player(string type); //initializes player with race type, and changes race attribute for display purposes
    void default_layout();
    void move_player(Direction d); //moves player in d
    void use_pot_player(Direction d); //makes player use potion in d
    void generate_in_chambers(); //chambers generate items and enemies
    void test_chambers(); //for testing chambers, delete later!
    void reset_chambers(); //regenerates all chambers
    bool valid_direction();
    void update_observers();
    friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};


#endif
