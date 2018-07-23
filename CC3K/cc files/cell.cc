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

void Cell::toggle_stair() {
    if (stair) stair = false;
    else stair = true;
}

void set_stair_off();

void Cell::clear(){
    if (has_stair()) toggle_stair();
    delete ob;
    ob = nullptr;
    player = nullptr;
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
    try {
        whoTo.acceptMove(*this);
    }
    catch (Move_Unsuccessful &o) {
        throw;
    }
    player = nullptr;
}

void Cell::acceptMove(Cell &whoFrom) {
    if (has_stair()) throw Stair_Cell();
    else if (!isOccupied()) {
        setPlayer(whoFrom.getPlayer());
        notifyObservers();
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
void Cell::attack(Cell &target) {
    //to write
}
void Cell::use(Cell &target) {
    //to write
} 
void notifyDisplay() { 
    //to write
}

