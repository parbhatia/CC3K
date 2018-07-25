#ifndef cell_hpp
#define cell_hpp
#include <vector>
#include <iostream>
#include "object.h"
#include "info.h"
#include "player.h"

class TextDisplay;
class Object;
class Cell {
    int row, col;
    bool hasdragon = false;
    bool hasmoved = false;
    bool haspotion = false;
    bool hasgold = false;
    bool hasstair = false;
    char type = ' ';
    TextDisplay *td;
    std::vector<Cell *> observers;
protected:
    Player *player = nullptr;
    Object *ob = nullptr;
public:
    Cell(int r, int c, char t);
    bool has_dragon();
    void set_gold();
    bool has_gold();
    void reset_gold();
    void set_potion();
    bool has_potion();
    void reset_potion();
    bool has_moved();
    void set_moved();
    void reset_has_moved();
    virtual char print();
    int getRow();
    int getCol();
    bool hasPlayer();
    bool hasObject();
    bool has_stair();
    void set_stair();
    void clear_stair();
    bool isOccupied();
    void clear();
    virtual bool canDragon();
    virtual void setObject(Object *newob);
    virtual void setPlayer(Player *newob);
    virtual void moveTo(Cell &whoTo);
    virtual void acceptMove(Cell &whoFrom);
    virtual void attack(Cell &target);
    virtual void use(Cell &target);  
    virtual void notifyObservers();
    virtual void notify(Cell &whoFrom);
    void attachObserver(Cell* ob);
    void setDisplay(TextDisplay *td);
    void notifyDisplay();
    int sizeObservers();
    Player* getPlayer(); 
    Object* getObject();
    virtual ~Cell() = 0;
};

#endif
