#ifndef info_h
#define info_h
#include <map>
#include <string>
#include <iostream>

const int enemy_types = 8;
const int player_types = 5;
const int potion_types = 6;

//error codes to move in seperate file later
class No_More_Enemies {};
class No_More_Potions {};
class No_More_Gold {};

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

const std::map<std::string, std::string> player_name {
    std::pair <std::string, std::string> ("s", "Shade"),
    std::pair <std::string, std::string> ("d", "Drow"),
    std::pair <std::string, std::string> ("v", "Vampire"),
    std::pair <std::string, std::string> ("g", "Goblin"),
    std::pair <std::string, std::string> ("t", "Troll"),
};


//    if (rand_num == 5) return new Shade();
//
//    switch (rand_num) {
//        case 0:
//            return new Shade();
//            break;
//        case 1:
//            return new Shade();
//            break;
//        case 2:
//            return new Shade();
//            break;
//        case 3:
//            return new Shade();
//            break;
//        case 4:
//            return new Shade();
//            break;
//        case 5:
//            return new Shade();
//            break;
//    }
//}

/*
 const std::map<int, Object*> enemy_map {
 std::pair <int, Object*> (0, new Shade()),
 std::pair <int, Object*> (1, new Shade()),
 std::pair <int, Object*> (2, new Shade()),
 std::pair <int, Object*> (3, new Shade()),
 std::pair <int, Object*> (4, new Shade()),
 std::pair <int, Object*> (5, new Shade()),
 };
 */

#endif
