#ifndef GOLD_H
#define GOLD_H
#include "item.h"
#include <iostream>

class Dragon;

class Gold: public Item {
    int value;
    Dragon *dragon = nullptr;
public:
    Gold(int n = 0);
    void beUsed(Player* whoFrom) override;
    char print() override;
    void setDragon(Dragon *d);
    bool hasDragon();
    bool needsDragon();
    Dragon* getDragon();
    void notify(Player* p) override;
};
#endif
