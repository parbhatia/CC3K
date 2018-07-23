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
#include "merchant.h"

class Factory {
public:
    Object *EnemyFactory(int rand_num); //creates enemies based on random number passed
    Object *PlayerFactory(std::string s); //creates players based on string s
};


#endif
