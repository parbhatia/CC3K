#include "cell.h"
#include "object.h"
using namespace std;

Cell::Cell(int r, int c, char t): row{r},col{c},type{t}{}

Cell::~Cell(){
    clear();
}

int Cell::getRow() { return row; }

int Cell::getCol() { return col; }

bool Cell::hasPlayer() {
    return (player != nullptr);
}

bool Cell::has_stair() { return stair; }

void Cell::set_stair() { stair = true; }

void Cell::clear_stair() { stair = false; }

void Cell::clear(){
    if (has_stair()) clear_stair();
    delete ob;
    ob = nullptr;
    player = nullptr;
}

void Cell::attack(Cell &target) {
    Object *new_object = target.getObject();
    new_object->beAttacked(ob?ob:player);
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

void Cell::setPlayer(Player *newob){
    player = newob;
}

bool Cell::has_moved() { return hasmoved; }

void Cell::set_moved() { hasmoved = true; }

void Cell::reset_has_moved() { hasmoved = false; }

Player* Cell::getPlayer() {
    return player;
}

Object* Cell::getObject() {
    return ob;
}

char Cell::print() {
    if (stair) {
        return '/';
    } else if (player) {
        return player->print();
    } else if (ob) {
        return ob->print();
    } else {
        return type;
    }
}

void Cell::moveTo(Cell &whoTo) {
    //only move cell if it's not been moved on
    if (!has_moved()) {
        try {
            whoTo.acceptMove(*this);
        }
        catch(...) {
            //check that a player was trying to move
            //if it was, set whoFrom hasmoved to be true
            if (hasPlayer()) {
                set_moved();
            }
            throw;
        }
        //move was successful
        player = nullptr;
        ob = nullptr;
    }
}

void Cell::acceptMove(Cell &whoFrom) {
    if (has_stair() && whoFrom.hasPlayer()) throw Stair_Cell();
    else if (!isOccupied())  {
        //only one object will be set
        setPlayer(whoFrom.getPlayer());
        setObject(whoFrom.getObject());
        notifyObservers();
        set_moved();
    } else {
        throw Move_Unsuccessful();
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
void Cell::use(Cell &target) {
    Object *new_object = target.getObject();
    if (new_object) new_object->beUsed(player);
} 
void notifyDisplay() { 
    //to write
}

