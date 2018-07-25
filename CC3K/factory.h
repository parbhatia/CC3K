#ifndef factory_hpp
#define factory_hpp
#include <iostream>
#include "player.h"
#include "dwarf.h"
#include "shade.h"
#include "orc.h"
#include "elf.h"
#include "halfling.h"
#include "drow.h"
#include "vampire.h"
#include "human.h"
#include "potion.h"
#include "resHP.h"
#include "poiHP.h"
#include "gold.h"
#include "merchant.h"
#include "troll.h"
#include "dragon.h"
#include "goblin.h"

class Factory {
public:
    Object *EnemyFactory(int rand_num); //creates enemies based on random number passed
    Player *PlayerFactory(std::string s); //creates players based on string s
    Potion *PotionFactory(int rand_num);
    Gold *GoldFactory(int rand_num);
};


//gold is 5/8 chance of normal, 1/8 dragon hoard, 1/4 small hoard.


#endif
