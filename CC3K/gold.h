#ifndef GOLD_H
#define GOLD_H
#include "item.h"

class Gold: public Item {
    int value;
public:
    Gold(int n = 0);
    void beUsed(Player* whoFrom) override;
    char print() override;
};
#endif