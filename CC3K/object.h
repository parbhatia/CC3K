#ifndef OBJECT_H_
#define OBJECT_H_

class Halfling;
class Dwarf;
class Goblin;
class Drow;

class Object {
public:
    virtual char print()=0;
    virtual void interact(Object *whoTo)=0;
    virtual void acceptInteract(Object *whoFrom)=0; 
    virtual void interact(Halfling* h);
    virtual void interact(Dwarf* d);
    virtual void interact(Drow* h);
    virtual void interact(Goblin* g);
};

#endif