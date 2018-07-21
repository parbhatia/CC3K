#ifndef info_h
#define info_h
#include <map>
#include <string>
#include <iostream>
#include "player.h"
#include "dwarf.h"
#include "shade.h"

//std::map <int, int> mymap =
//{
//    std::pair <int, int> (1, 1),
//    std::pair <int, int> (2, 2),
//    std::pair <int, int> (2, 2)
//};

enum class Direction { NW, N, NE, W, E, SW, S, SE };

const std::map<std::string, Direction> dir_map {
    std::pair <std::string, Direction> ("no", Direction::N),
    std::pair <std::string, Direction> ("so", Direction::S),
    std::pair <std::string, Direction> ("ea", Direction::E),
    std::pair <std::string, Direction> ("we", Direction::W),
    std::pair <std::string, Direction> ("ne", Direction::NE),
    std::pair <std::string, Direction> ("nw", Direction::NW),
    std::pair <std::string, Direction> ("se", Direction::SE),
    std::pair <std::string, Direction> ("sw", Direction::SW),
};

const std::map<int, Player*> enemy_map {
    std::pair <int, Player*> (0, new Shade()),
    std::pair <int, Player*> (1, new Shade()),
    std::pair <int, Player*> (2, new Shade()),
    std::pair <int, Player*> (3, new Shade()),
    std::pair <int, Player*> (4, new Shade()),
    std::pair <int, Player*> (5, new Shade()),
};


#endif
