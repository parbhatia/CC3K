#ifndef textdisplay_hpp
#define textdisplay_hpp
#include <iostream>
#include <iostream>
#include <vector>
using namespace std;

class Grid;

class TextDisplay {
    int size;
    std::vector <std::vector <char>> cells;
public:
    TextDisplay();
};

std::ostream &operator<<(std::ostream &out, const TextDisplay &g);

#endif
