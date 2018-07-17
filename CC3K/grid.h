#ifndef grid_hpp
#define grid_hpp

#include <iostream>
#include <vector>
#include "textdisplay.h"
#include "cell.h"

class TextDisplay;

class Grid {
    int size;
    TextDisplay td;
    vector <vector <Cell>> cells>;
public:
    Grid();
    ~Grid();
    void default_layout(string s);
    void read_layout();
    bool valid_direction();
    void update_observers();
};


#endif /* grid_hpp */
