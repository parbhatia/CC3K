#ifndef OBJECT_H_
#define OBJECT_H_
class Item;
class Character;
class Player;
class Halfling;
class Dwarf;
class Goblin;
class Drow;
class Enemy;

class Object {
public:
    virtual ~Object()=0;
    virtual char print()=0;
    virtual void beAttacked(Object *whoFrom)=0;
    virtual void attack(Item *whoTo)=0;
    virtual void attack(Player *p);
    virtual void attack(Enemy *e);
    virtual void beUsed(Player *whoFrom)=0;
    virtual void attack(Halfling *h);
    virtual void attack(Dwarf *d);
    virtual void attack(Drow *d);  
    virtual void attack(Goblin *g);
    virtual void notify(Player* p)=0;
    virtual bool getHostile();
   
    virtual Object* spawn();
    virtual void setDragon(Object *d);
    virtual bool hasDragon();
    virtual bool needsDragon();
    virtual Object* getDragon();
    virtual void setHostile(bool n=true);
    virtual void setDGold(Object* g);
    virtual Object* getDGold();
};

#endif
