#include "object.h"

Object::~Object() {}
void Object::attack(Halfling *h) {}
void Object::attack(Dwarf *d) {}
void Object::attack(Drow *d) {}
void Object::attack(Goblin *g) {}
void Object::attack(Player *p) {}
void Object::attack(Enemy *e) {}
bool getHostile() {return true;}