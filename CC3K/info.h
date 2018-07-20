#ifndef info_h
#define info_h
#include <map>
#include "dwarf.h"

enum class Direction { NW, N, NE, W, E, SW, S, SE };
std::map<std::string, Direction> dir_map = {
    {"no", Direction::N},
    {"so", Direction::S},
    {"ea", Direction::E},
    {"we", Direction::W},
    {"ne", Direction::NE},
    {"nw", Direction::NW},
    {"se", Direction::SE},
    {"sw", Direction::SW},
};

std::map<int, Enemy> enemy_map = {
    {0, Dwarf()},
    {1, Dwarf()},
    {2, Dwarf()},
    {3, Dwarf()},
    {4, Dwarf()},
    {5, Dwarf()}
    //add more later
};



#endif
