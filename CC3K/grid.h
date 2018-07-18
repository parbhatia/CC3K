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
//#include "character.h"

using namespace std;

static int num_enemies = 20;
static int num_items = 20; //???

class Grid {
    int width = 79;
    int height = 30;
    std::vector <std::vector <Cell*>> cells;
    int level = 1;
    string race = "Shade";
    //Character *player = nullptr;
    std::vector <Chamber> chambers;
public:
    Grid();
    //~Grid();
    void read_layout(string s);
    //void set_player(string race); //sets player's race for display purposes
    void default_layout();
    void generate_chamber();
    void test_chambers(); //for testing chambers, delete later!
    void reset_chambers(); //regenerates all chambers
    bool valid_direction();
    void update_observers();
    friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};


#endif
