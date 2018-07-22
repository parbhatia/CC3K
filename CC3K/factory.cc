#include "factory.h"
using namespace std;

Object *Factory::EnemyFactory(int rand_num) {
    if (rand_num == 0) return new Dwarf();
    else if (rand_num == 1) return new Dwarf();
    else if (rand_num == 2) return new Elf();
    else if (rand_num == 3) return new Orc();
    else if (rand_num == 4) return new Halfling();
    else if (rand_num == 5) return new Dwarf();
    else if (rand_num == 6) return new Dwarf();
    else if (rand_num == 7) return new Dwarf();
    else return new Dwarf();
}

Object *Factory::PlayerFactory(string s) {
    if (s == "d") return new Drow();
    else if (s == "v") return new Vampire();
    else if (s == "g") return new Shade (); //change to Goblin();
    else if (s == "t") return new Shade(); //change to Troll();
    else return new Shade();
}
