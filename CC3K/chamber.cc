#include "chamber.h"
#include <iostream>
using namespace std;

int Chamber::numPotions = 10;
int Chamber::numGold = 10;
int Chamber::numEnemies = 20;

void Chamber::print() {
    for (auto cell : cells) {
        std::cout << cell->print() << " ";
    }
    std::cout << std::endl;
}

void Chamber::reset() {
    for (auto cell : cells) {
        cell->clear();
    }
}

void Chamber::add_cell(Cell *c) {
    cells.emplace_back(c);
}


void Chamber::generate_player(string type) {
    bool done = false;
    while (!done) {
        int x = rand() % cells.size(); //generates number from 0 to sizeof cells
        if (!cells[x]->isOccupied()) {
            //set player based on type
            Object *new_player = nullptr;
            //set to use map later
            if (type == "s") new_player = new Shade();
            //else if (type == "v") new_player = new Vampire();
            cells[x]->setObject(new_player);
            done = true;
        }
    }
}
/*
void Chamber::generate_potion() {
    srand((unsigned)time(NULL)); //uses "seed" as current time
    if (numPotions == 10) {
        return;
    }
    else {
        bool done = false;
        while (!done) {
            int x = rand() % cells.size(); //generates number from 0 to sizeof cells
            if (!cells[x]->isOccupied()) {
                cells[x]->setObject();
                done = true;
            }
        }
    }
}

void Chamber::generate_gold() {
    srand((unsigned)time(NULL)); //uses "seed" as current time
    if (numGold == 0) {
        return;
    }
    else {
        bool done = false;
        while (!done) {
            int x = rand() % cells.size(); //generates number from 0 to sizeof cells
            if (!cells[x]->isOccupied()) {
                cells[x]->setObject();
                done = true;
            }
        }
    }
}
*/
void Chamber::generate_enemy() {
    srand((unsigned)time(NULL)); //uses "seed" as current time
    if (numGold == 0) {
        return;
    }
    else {
        bool done = false;
        while (!done) {
            int x = rand() % cells.size(); //generates number from 0 to sizeof cells
            if (!cells[x]->isOccupied()) {
                //int y = rand() % 6;
                //choose random enemy
                Object *new_enemy = new Shade();
                //Object *new_enemy = new enemy_map[y];
                cells[x]->setObject(new_enemy);
                done = true;
            }
        }
    }
   
}
