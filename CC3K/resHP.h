#include "potion.h"
#include "player.h"

class resHP:public Potion{
    void beUsed(Player *whoFrom) override;

};