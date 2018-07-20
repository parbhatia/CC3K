#include "cell.h"
#include "object.h"
Cell::Cell(int r, int c): row{r},col{c}{}
Cell::~Cell(){
    delete player;
    delete ob;
}

int Cell::getRow() { return row; }

int Cell::getCol() { return col; }

bool Cell::hasPlayer(){
    if(player){
        return true;
    }
    else{
        return false;
    }
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

void Cell::moveTo(Cell &whoTo) {
    if (whoTo.acceptMove(*this)) {
        delete player;
    }
}

bool Cell::acceptMove(Cell &whoFrom) {
    if (!isOccupied()) {
        player = whoFrom.getPlayer();
        notifyObservers();
        return true;
    } else {
        return false;
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
//void Cell::attack(Cell &target);
//void Cell::use(Cell &target);  
//void notifyDisplay() { 
//}

