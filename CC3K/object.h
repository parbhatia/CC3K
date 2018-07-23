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
    virtual char print()=0;
    virtual void beAttacked(Object *whoFrom)=0;
    virtual void attack(Item *whoTo)=0;
    virtual void attack(Character *whoTo)=0;
    virtual void attack(Halfling *h){}
    virtual void attack(Dwarf *d){}
<<<<<<< HEAD
    virtual void attack(Drow *d){}
=======
    virtual void attack(Drow *h){}
>>>>>>> 4929542f41ae277c164d8952d550a181722ffaea
    virtual void attack(Goblin *g){}
    virtual void attack(Drow *h){}   //enemy
    virtual void attack(Goblin *g){}  //enemy
    virtual void beUsed(Player *whoFrom)=0;
    virtual ~Object() = 0;
};

#endif
