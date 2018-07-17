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
    void move_to(Cell& to);
    bool accept_move(Cell &who);
    void interact(Cell &target);
    void accept_interact(Cell &whoFrom);
    std::string print();
    void notifyObservers();
    void notify(Cell &whoFrom);
    Object& getObject();
    void attachObserver(Cell* ob);
    
};



#endif
