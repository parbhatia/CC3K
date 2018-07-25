#include "object.h"
#include "dragon.h"

Object::~Object() {}
void Object::attack(Halfling *h) {}
void Object::attack(Dwarf *d) {}
void Object::attack(Drow *d) {}
void Object::attack(Goblin *g) {}
void Object::attack(Player *p) {}
void Object::attack(Enemy *e) {}
bool Object::getHostile() {return true;}
Object* Object::spawn() {
    return nullptr;
}
void Object::setDragon(Object *d) {}
bool Object::hasDragon() {return false;}
bool Object::needsDragon() {return false;}
Object* getDragon() {return nullptr;}
void Object::setHostile(bool n) {}