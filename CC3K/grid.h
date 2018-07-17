#ifndef grid_hpp
#define grid_hpp

#include <iostream>

class Grid {
    int size;
    TextDisplay td;
    vector <<vector Cell> cells>;
public:
    void default_layout();
    void read_layout();
    bool valid_direction();
    void update_observers();
};


#endif /* grid_hpp */
