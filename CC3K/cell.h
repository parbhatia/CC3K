#ifndef cell_hpp
#define cell_hpp
#include <vector>
#include <iostream>
#include "object.h"
#include "info.h"

class TextDisplay;
class Object;
class Cell {
    int row, col;
    bool hasmoved = false;
    char type = ' ';
    bool stair; //determines if cell is stair
    TextDisplay *td;
    std::vector<Cell *> observers;
protected:
    Object *player = nullptr;
    Object *ob = nullptr;
public:
    Cell(int r, int c, char t);
    bool has_moved();
    void set_moved();
    void reset_has_moved();
    virtual char print();
    int getRow();
    int getCol();
    bool hasPlayer();
    bool has_stair();
    void toggle_stair();
    bool isOccupied();
    void clear();
    virtual void setObject(Object *newob);
    virtual void setPlayer(Object *newob);
    virtual void moveTo(Cell &whoTo);
    virtual void acceptMove(Cell &whoFrom);
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
