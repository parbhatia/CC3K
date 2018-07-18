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

class TextDisplay;

class Grid {
    int width = 79;
    int height = 30;
    std::vector <std::vector <Cell*>> cells;
    //TextDisplay *td = nullptr;
    int level = 1;
    string race = "Shade";
    //Character *player = nullptr;
    std::vector <std::vector <Chamber>> chambers;
    static num_enemies = 20;
    static num_items = 20; //???
public:
    Grid();
    //~Grid();
    void read_layout(string s);
    //void set_player(string race); //sets player's race for display purposes
    void default_layout();
    void reset_chambers(); //regenerates all chambers
    bool valid_direction();
    void update_observers();
    friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};


#endif
