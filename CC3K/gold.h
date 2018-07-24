#ifndef GOLD_H
#define GOLD_H
#include "item.h"

class Gold: public Item {
    int value;
    void beUsed(Player* whoFrom) override;
};
#endif