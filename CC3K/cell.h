#ifndef cell_hpp
#define cell_hpp
#include <vector>
#include <iostream>
#include "object.h"

class TextDisplay;
class Object;
class Cell {
    int row, col;
    TextDisplay *td;
    std::vector<Cell *> observers;
protected:
    Object *player = nullptr;
    Object *ob = nullptr;
public:
    Cell(int r, int c);
    virtual char print() = 0;
    int getRow();
    int getCol();
    bool hasPlayer();
    bool isOccupied();
    void clear();
    virtual void setObject(Object *newob);
    virtual void setPlayer(Object *newob);
    virtual int moveTo(Cell &whoTo);
    virtual int acceptMove(Cell &whoFrom); 
    virtual void attack(Cell &target);
    virtual void use(Cell &target);  
    virtual void notifyObservers();
    virtual void notify(Cell &whoFrom);
    void attachObserver(Cell* ob);
    void setDisplay(TextDisplay *td);
    void notifyDisplay(); 
    Object* getPlayer(); 
    Object* getObject();
    virtual ~Cell() = 0;
};

#endif
