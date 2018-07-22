#include "factory.h"

Object *Factory::EnemyFactory(int rand_num) {
    if (rand_num == 0) return new Shade();
    else if (rand_num == 1) return new Shade();
    else if (rand_num == 2) return new Shade();
    else if (rand_num == 3) return new Shade();
    else if (rand_num == 4) return new Shade();
    else if (rand_num == 5) return new Shade();
    else if (rand_num == 6) return new Shade();
    else if (rand_num == 7) return new Shade();
    else return new Shade();
}
