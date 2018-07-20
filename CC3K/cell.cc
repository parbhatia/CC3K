#include "cell.h"
#include "object.h"
Cell::Cell(int r, int c): row{r},col{c}{}
Cell::~Cell(){}
//void Cell::setDisplay(TextDisplay *td){
//    this->td = td;
//}
//
//void Cell::attachObserver(Cell* ob){
//    observers.emplace_back(ob);
//}
//
//Object& Cell::getObject(){
//    return *ob;
//}
//
//void Cell::notifyObservers(){
//    for(auto ob: observers){
//        ob->notify(*this);
//    }
//}

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
}

bool Cell::isOccupied(){
    if(hasPlayer() or ob){
        return true;
    }
    else{
        return false;
    }
}

void Cell::setEnemy(){
    //NEED TO WRITE
}

void Cell::setPotion(){
    //NEED TO WRITE
}

void Cell::setGold(){
    //NEED TO WRITE
}

Object* Cell::getPlayer() {
    return player;
}