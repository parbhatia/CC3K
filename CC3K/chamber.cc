#include "chamber.h"
#include <iostream>

void Chamber::print(){
    for(auto cell: cells){
        std::cout<< cell->print() << " ";
    }
    std::cout<< std::endl;
}

void Chamber::reset(){
    for(auto cell:cells){
        cell->clear();
    }
}

void Chamber::generate_potion(){
    srand((unsigned)time(NULL)); //uses "seed" as current time
    if(numPotions>=10){
        return;
    }
    else{
        bool done = false;
        while(!done){
            int x = rand() % cells.size(); //generates number from 0 to sizeof cells
            if(cells[x]->isOccupied()){
                 cells[x]->setPotion();
                 done = true;
            }
        }

    }
}

void Chamber::generate_gold(){
    srand((unsigned)time(NULL)); //uses "seed" as current time
    if(numGold>=10){
        return;
    }
    else{
        bool done = false;
        while(!done){
            int x = rand() % cells.size(); //generates number from 0 to sizeof cells
            if(cells[x]->isOccupied()){
                 cells[x]->setGold();
                 done = true;
            }
        }

    }
}

void Chamber::generate_enemy(){
    srand((unsigned)time(NULL)); //uses "seed" as current time
    if(numGold>=10){
        return;
    }
    else{
        bool done = false;
        while(!done){
            int x = rand() % cells.size(); //generates number from 0 to sizeof cells
            if(cells[x]->isOccupied()){
                 cells[x]->setEnemy();
                 done = true;
            }
        }

    }
}