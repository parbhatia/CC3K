#ifndef info_h
#define info_h
#include <map>

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

#endif
