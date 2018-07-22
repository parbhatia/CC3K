#ifndef factory_hpp
#define factory_hpp
#include <iostream>
#include "player.h"
#include "dwarf.h"
#include "shade.h"

class Factory {
public:
    Object *EnemyFactory(int rand_num); //creates enemies based on random number passed
};


#endif
