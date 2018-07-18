#include <vector>
#include "cell.h"

class Chamber{
    std::vector<Cell*> cells;
    static int numPotions, numGold, numEnemies;
public:

    void generate_potion();
    void generate_gold();
    void reset();
};

srand((unsigned)time(NULL)); //uses "seed" as current time
int x = rand() % 5; //generates number from 0 to 4
