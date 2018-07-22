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

int Chamber::cell_picker() {
    return rand() % cells.size();
}

int Chamber::enemy_picker() {
    return rand() % enemy_types;
}

void Chamber::generate_player(string type) {
    bool done = false;
    while (!done) {
        int x = cell_picker();
        if (!cells[x]->isOccupied()) {
            //set player based on type
            Object *new_player = nullptr;
            if (type == "s") new_player = new Shade();
            //else if (type == "v") new_player = new Vampire();
            cells[x]->setObject(new_player);
            done = true;
        }
    }
}
/*
void Chamber::generate_potion() {
    if (numPotions == 0) {
        throw No_More_Potions();
    }
    else {
        bool done = false;
        while (!done) {
            int x = cell_picker();
            if (!cells[x]->isOccupied()) {
                cells[x]->setObject();
                done = true;
            }
        }
 --numPotions;
    }
}

void Chamber::generate_gold() {
    if (numGold == 0) {
        throw No_More_Gold();
    }
    else {
        bool done = false;
        while (!done) {
            int x = cell_picker();
            if (!cells[x]->isOccupied()) {
                cells[x]->setObject();
                done = true;
            }
        }
    }
 --numGold;
}
*/

void Chamber::generate_enemy() {
    if (numEnemies == 0) {
        throw No_More_Enemies();
    }
    else {
        bool done = false;
        while (!done) {
            int x = cell_picker();
            if (!cells[x]->isOccupied()) {
                int y = enemy_picker();
                //choose random enemy
                Object *new_enemy = f.EnemyFactory(y);
                cells[x]->setObject(new_enemy);
                --numEnemies;
                done = true;
            }
        }
    }
   
}
