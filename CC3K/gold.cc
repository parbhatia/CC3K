#include "gold.h"
#include "player.h"
#include "dragon.h"

Gold::Gold(int n):value{n}, dragon{nullptr} {}
using namespace std;

void Gold::beUsed(Player* whoFrom) {
    whoFrom->changeGold(value);
}
char Gold::print() {
    return 'G';
}

void Gold::setDragon(Object *d) {
    dragon = d;
}

Object* Gold::getDragon() {
    return dragon;
}

void Gold::notify(Player* p) {
    if (dragon) {
        dragon->setHostile(true);
        p->beAttacked(dragon);
    }
}
bool Gold::hasDragon() {
    return (dragon != nullptr);
}

bool Gold::needsDragon() {
    return (value == 6);
}