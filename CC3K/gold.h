#ifndef GOLD_H
#define GOLD_H
#include "item.h"
#include <iostream>

class Dragon;

class Gold: public Item {
    int value;
    Object *dragon = nullptr;
public:
    Gold(int n = 0);
    void beUsed(Player* whoFrom) override;
    char print() override;
    void setDragon(Object *d) override;
    bool hasDragon() override;
    bool needsDragon() override;
    Object* getDragon() override;
    void notify(Player* p) override;
};
#endif
