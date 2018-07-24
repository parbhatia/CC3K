#include "gold.h"
#include "player.h"
Gold::Gold(int n):value{n} {}

void Gold::beUsed(Player* whoFrom) {
    whoFrom->changeGold(value);
}
char Gold::print() {
    return 'G';
}