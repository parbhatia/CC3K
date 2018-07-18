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
//#include "character.h"

using namespace std;

class TextDisplay;

class Grid {
    int width = 79;
    int height = 30;
    std::vector <std::vector <Cell*>> cells;
    TextDisplay *td = nullptr;
    int level = 1;
    string race = "Shade";
    //Character *player = nullptr;
public:
    Grid();
    //~Grid();
    void read_layout(string s);
    //void set_player(string race);
    void default_layout();
    bool valid_direction();
    void update_observers();
    friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};


#endif
