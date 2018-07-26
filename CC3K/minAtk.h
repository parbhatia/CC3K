#ifndef _MIN_ATK_H_
#define _MIN_ATK_H_
#include "potion.h"

class MinAttack: public Potion {
public:
    void beUsed(Player *whoFrom) override;
    ~MinAttack();
};
#endif
