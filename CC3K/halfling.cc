#include "halfling.h"

char Halfling::print(){
    return 'L';
}

Halfling::Halfling() : Enemy{15, 20, 100} {}