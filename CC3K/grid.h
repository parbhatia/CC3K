#ifndef grid_hpp
#define grid_hpp
#include <iostream>
#include <vector>
#include "textdisplay.h"
#include "cell.h"
using namespace std;

class TextDisplay;

class Grid {
    int size;
    TextDisplay td;
    std::vector <std::vector <Cell>> cells;
public:
    Grid();
    ~Grid();
    void default_layout(string s);
    void read_layout();
    bool valid_direction();
    void update_observers();
};

void operator<<(string out, Grid *g) {
    
}

#endif
