#include "bridge.h"
Bridge::Bridge(int r, int c): Cell(r, c){}

char Bridge::print() {
    return '#';
}