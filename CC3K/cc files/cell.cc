#include "cell.h"
#include "object.h"
using namespace std;

Cell::Cell(int r, int c): row{r},col{c}{}
Cell::~Cell(){
    delete player;
    delete ob;
}

int Cell::getRow() { return row; }

int Cell::getCol() { return col; }

bool Cell::hasPlayer() {
    return (player != nullptr);
}


void Cell::clear(){
    delete ob;
    delete player;
}

bool Cell::isOccupied(){
    if(hasPlayer() || ob){
        return true;
    }
    else{
        return false;
    }
}

void Cell::setObject(Object *newob){
    ob = newob;
}

void Cell::setPlayer(Object *newob){
    player = newob;
}

Object* Cell::getPlayer() {
    return player;
}

Object* Cell::getObject() {
    return ob;
}

char Cell::print() {
    if (player) {
        return player->print();
    } else if (ob) {
        return ob->print();
    } else {
        return ' ';
    }
}

int Cell::moveTo(Cell &whoTo) {
    int move_code = whoTo.acceptMove(*this);
    if (move_code == 1) { //if player move was successful
        player = nullptr;
        return 1;
    } else if (move_code == 2) { //if player moves on door
        player = nullptr;
        return 2;
    } else return 0;
}

int Cell::acceptMove(Cell &whoFrom) {
    if (!isOccupied()) {
        setPlayer(whoFrom.getPlayer());
        notifyObservers();
        return 1;
    } else {
        return 0;
    }
}

void Cell::notifyObservers() {
    for (auto it : observers) {
        it->notify(*this);
    }
}
void Cell::notify(Cell &whoFrom) {
    if (ob) {
        whoFrom.getPlayer()->beAttacked(ob);
    }
}
void Cell::attachObserver(Cell* ob) {
    observers.emplace_back(ob);
}
void setDisplay(TextDisplay *td) {
    td = td;
}
void Cell::attack(Cell &target) {
    //to write
}
void Cell::use(Cell &target) {
    //to write
} 
void notifyDisplay() { 
    //to write
}

