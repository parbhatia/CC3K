#include "cell.h"
#include "object.h"
using namespace std;

Cell::Cell(int r, int c, char t): row{r},col{c},type{t}{}

Cell::~Cell(){ clear(); }

int Cell::getRow() { return row; }

int Cell::getCol() { return col; }

bool Cell::hasPlayer() { return (player != nullptr); }

bool Cell::hasObject() { return (ob!= nullptr); }

void Cell::setObject(Object *newob){ ob = newob; }

void Cell::setPlayer(Player *newob){ player = newob; }

Player* Cell::getPlayer() { return player; }

Object* Cell::getObject() { return ob; }

//moved
bool Cell::has_moved() { return hasmoved; }

void Cell::set_moved() { hasmoved = true; }

void Cell::reset_has_moved() { hasmoved = false; }
///////

//gold
void Cell::set_gold() { hasgold = true; }

bool Cell::has_gold() { return hasgold; }

void Cell::reset_gold() { hasgold = false; }
//////

//potion
void Cell::set_potion() { haspotion = true; }

bool Cell::has_potion() { return haspotion; }

void Cell::reset_potion() { haspotion = false; }
////////

//stair
bool Cell::has_stair() { return hasstair; }

void Cell::set_stair() { hasstair = true; }

void Cell::clear_stair() { hasstair = false; }
///////

void Cell::clear() {
    clear_stair();
    reset_gold();
    reset_potion();
    reset_has_moved();
    delete ob;
    ob = nullptr;
    player = nullptr;
}

void Cell::attack(Cell &target) {
    Object *p = this->getPlayer();
    Object *new_object = nullptr;
    if (target.hasObject()) {
        new_object = target.getObject();
        new_object->beAttacked(p);
    } else if (target.hasPlayer()) {
        new_object = target.getPlayer();
        new_object->beAttacked(p);
    } else {}
}

bool Cell::isOccupied(){
    if(hasPlayer() || ob){
        return true;
    } return false;
}

char Cell::print() {
    if (hasstair) {
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
    //only move cells with players and objects
    if (!has_moved() && !has_potion() && !has_gold()) {
        try {
            whoTo.acceptMove(*this);
        }
        catch(...) {
            //check that a player was trying to move
            //if it was, set whoFrom hasmoved to be true
            if (hasPlayer()) { set_moved(); }
            throw;
        }
        //move was successful
        player = nullptr;
        ob = nullptr;
    }
}

void Cell::acceptMove(Cell &whoFrom) {
    if (has_stair() && whoFrom.hasPlayer()) throw Stair_Cell();
    else if (has_stair() && whoFrom.hasObject()) { throw Move_Unsuccessful();
    }
    else if (has_gold() && whoFrom.hasObject()) { throw Move_Unsuccessful();
    }
    else if (has_gold() && whoFrom.hasPlayer()) {
        if (has_gold()) {
            cout << "PLAYER USING GOLD" << endl;
            ob->beUsed(whoFrom.getPlayer());
            delete ob;
            ob = nullptr;
            reset_gold();
        }
        //only one object will be set
        setPlayer(whoFrom.getPlayer());
        setObject(whoFrom.getObject());
        set_moved();
    }
    else if (!isOccupied())  {
        //only one object will be set
        setPlayer(whoFrom.getPlayer());
        setObject(whoFrom.getObject());
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
    Player* p = whoFrom.getPlayer();
    if (ob) { ob->notify(p);}
}
void Cell::attachObserver(Cell* ob) {
    observers.emplace_back(ob);
}
void setDisplay(TextDisplay *td) {td = td; }

void Cell::use(Cell &target) {
    Object *new_object = target.getObject();
    if (new_object) {
        try {
            new_object->beUsed(player);
        }
        catch (...) {
            delete target.ob;
            target.ob = nullptr;
            target.reset_potion();
            throw;
        }
    }
}

int Cell::sizeObservers() {
    return observers.size();
}

void notifyDisplay() { 
    //to write
}

