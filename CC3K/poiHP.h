#ifndef POIHP_H
#define POIHP_H
#include "potion.h"

class poiHP: public Potion {
public:
    void beUsed(Player *whoFrom) override;
    ~poiHP();
};
#endif