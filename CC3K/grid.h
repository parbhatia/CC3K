#ifndef grid_hpp
#define grid_hpp
#include <iostream>
#include <vector>
#include "textdisplay.h"
#include "cell.h"
#include "doorcell.h"
#include "floorcell.h"
#include "nullcell.h"
#include "bridge.h"

using namespace std;

class TextDisplay;

class Grid {
    int width = 79;
    int height = 30;
    std::vector <std::vector <Cell*>> cells;
    TextDisplay *td = nullptr;
public:
    Grid();
    //~Grid();
    void read_layout(string s);
    void default_layout();
    bool valid_direction();
    void update_observers();
    friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};


#endif
