#ifndef OBJECT_H_
#define OBJECT_H_
class Item;
class Character;
class Player;
class Halfling;
class Dwarf;
class Goblin;
class Drow;

class Object {
public:
    virtual ~Object()=0;
    virtual char print()=0;
    virtual void beAttacked(Object *whoFrom)=0;
    virtual void attack(Item *whoTo)=0;
    virtual void attack(Character *whoTo)=0;
    virtual void beUsed(Player *whoFrom)=0;
    virtual void attack(Halfling *h);
    virtual void attack(Dwarf *d);
    virtual void attack(Drow *h);
    virtual void attack(Goblin *g);
};

#endif
