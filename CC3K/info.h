#ifndef info_h
#define info_h
#include <map>
#include <string>
#include <iostream>

const int enemy_distribution_number = 18;
const int player_types = 5;
const int potion_types = 6;
const int gold_distribution_number = 8;

//error codes to move in seperate file later
class No_More_Enemies {};
class No_More_Potions {};
class No_More_Gold {};
class Move_Unsuccessful {};
class Stair_Cell {};
class InvalidRange {};
class PickUpGold {};
class Game_Won {};
class Game_Lost {};
class Set_Dragon {
    Object *d
public:
    Object *d = nullptr;
    
}

//number of enemies and items
const int globalPotions = 10;
const int globalGold = 10;
const int globalEnemies = 20;

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


#endif
