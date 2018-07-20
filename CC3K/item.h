#ifndef item_hpp
#define item_hpp
#include <iostream>
#include "object.h"

class Item:public Object{
  virtual char print();
  virtual void beAttacked(Object *whoFrom);
  virtual void attack(Item *whoTo);
  virtual void attack(Character *whoTo);
  virtual void beUsed(Player *whoFrom);
};




#endif
