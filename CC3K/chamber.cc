#include "chamber.h"
#include <iostream>
using namespace std;

int Chamber::numPotions = 10;
int Chamber::numGold = 10;
int Chamber::numEnemies = 20;

void Chamber::clear() {
    numPotions = globalPotions;
    numGold = globalGold;
    numEnemies = globalEnemies;
}

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

//assumes chamber has player cell
Cell* Chamber::give_playercell() {
    for (auto cell: cells) {
        if (cell->hasPlayer()) return cell;
    }
    return 0;
}

//assumes chamber has player
Player* Chamber::give_player() {
    for (auto cell: cells) {
        if (cell->hasPlayer()) return cell->getPlayer();
    }
    return 0;
}

void Chamber::add_cell(Cell *c) {
    cells.emplace_back(c);
}

int Chamber::cell_picker() {
    return rand() % cells.size();
}

int Chamber::enemy_picker() {
    return rand() % enemy_distribution_number;
}

int Chamber::potion_picker() {
    return rand() % potion_types;
}

void Chamber::generate_player_cell(Player *p) {
    bool done = false;
    while (!done) {
        int x = cell_picker();
        if (!cells[x]->isOccupied()) {
            cells[x]->setPlayer(p);
            done = true;
        }
    }
}

void Chamber::generate_player(string type) {
    bool done = false;
    while (!done) {
        int x = cell_picker();
        if (!cells[x]->isOccupied()) {
            Player *new_player = f.PlayerFactory(type);
            cells[x]->setPlayer(new_player);
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

void Chamber::generate_stairs() {
    bool done = false;
    while (!done) {
        int x = cell_picker();
        if (!cells[x]->isOccupied()) {
            cells[x]->set_stair();
            done = true;
        }
    }
}

void Chamber::generate_potion() {
    if (numPotions == 0) {
        throw No_More_Potions();
    }
    else {
        bool done = false;
        while (!done) {
            int x = cell_picker();
            if (!cells[x]->isOccupied()) {
                int y = potion_picker();
                //choose random potion
                Object *new_pot = f.PotionFactory(y);
                cells[x]->setObject(new_pot);
                --numPotions;
                done = true;
            }
        }
    }
}

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
