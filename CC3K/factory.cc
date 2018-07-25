#include "factory.h"
using namespace std;

//Based on probability distributions
//3 dwarfs
//4 humans
//5 halfings
//2 elfs
//2 orcs
//2 merchants
Object *Factory::EnemyFactory(int rand_num) {
    if (rand_num == 0) return new Dwarf();
    else if (rand_num == 1) return new Dwarf();
    else if (rand_num == 2) return new Dwarf();
    else if (rand_num == 3) return new Human();
    else if (rand_num == 4) return new Human();
    else if (rand_num == 5) return new Human();
    else if (rand_num == 6) return new Human();
    else if (rand_num == 7) return new Halfling();
    else if (rand_num == 8) return new Halfling();
    else if (rand_num == 9) return new Halfling();
    else if (rand_num == 10) return new Halfling();
    else if (rand_num == 11) return new Halfling();
    else if (rand_num == 12) return new Elf();
    else if (rand_num == 13) return new Elf();
    else if (rand_num == 14) return new Orc();
    else if (rand_num == 15) return new Orc();
    else if (rand_num == 16) return new Merchant();
    else return new Merchant();
}

Player *Factory::PlayerFactory(string s) {
    if (s == "d") return new Drow();
    else if (s == "v") return new Vampire();
    else if (s == "g") return new Goblin ();
    else if (s == "t") return new Troll();
    else return new Shade();
}

Potion *Factory::PotionFactory(int rand_num) {
    if (rand_num == 0) return new poiHP();
    else if (rand_num == 1) return new resHP();
    else if (rand_num == 2) return new PlusAttack();
    else if (rand_num == 3) return new PlusDef();
    else if (rand_num == 4) return new MinDef();
    else return new MinAttack();
}

Gold *Factory::GoldFactory(int rand_num) {
    if (rand_num == 0) return new Gold(2);
    else if (rand_num == 1) return new Gold(6); //2
    else if (rand_num == 2) return new Gold(6); //2
    else if (rand_num == 3) return new Gold(6); //2
    else if (rand_num == 4) return new Gold(6); //2
    else if (rand_num == 5) return new Gold(6);
    else if (rand_num == 6) return new Gold(1);
    else if (rand_num == 7) return new Gold(1);
    else return new Gold(4); //merchant hoard
}

