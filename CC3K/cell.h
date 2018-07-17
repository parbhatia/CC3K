#ifndef cell_hpp
#define cell_hpp
#include <vector>
#include <iostream>

class TextDisplay;
class Object;
class Cell {
    int row, col;
    TextDisplay *td;
    std::vector<std::vector<Cell*>> observers;
public:
    virtual void move_to(Cell& to);
    virtual bool accept_move(Cell &who);
    virtual void interact(Cell &target);
    virtual void accept_interact(Cell &whoFrom);
    virtual std::string print();
    virtual void notifyObservers();
    virtual void notify(Cell &whoFrom);
    virtual Object& getObject();
    virtual void attachObserver(Cell* ob);
    
    virtual ~Cell() = 0;
    
};



#endif
