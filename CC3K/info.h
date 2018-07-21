#ifndef info_h
#define info_h
#include <map>
#include <string>
#include <iostream>
#include "dwarf.h"
#include "shade.h"

enum class Direction { NW, N, NE, W, E, SW, S, SE };
std::map<std::string, Direction> dir_map;
dir_map["no"] = Direction::N;
dir_map.insert(std::pair<std::string, Direction>("no", Direction::N));

("no", Direction::N));
//= {
//    {"no", Direction::N},
//    {"so", Direction::S},
//    {"ea", Direction::E},
//    {"we", Direction::W},
//    {"ne", Direction::NE},
//    {"nw", Direction::NW},
//    {"se", Direction::SE},
//    {"sw", Direction::SW},
//};


std::map<int, Player> enemy_map;

//= {
//    {0, Shade()},
//    {1, Shade()},
//    {2, Shade()},
//    {3, Shade()},
//    {4, Shade()},
//    {5, Shade()}
//    //add more later
//};



#endif
