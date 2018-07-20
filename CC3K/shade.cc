#include "shade.h"

char Shade::print() {
    return 'S';
}

void Shade::acceptInteract(Object *whoFrom) {
    whoFrom->interact(this);
}

void Shade::interact(Character *whoTo) {
    whoTo->changeHp(getAtk() - whoTo->getDef());
}

void interact(Halfling* h) {}
void interact(Dwarf* d) {}
void interact(Drow* h) {}
void interact(Goblin* g) {}
