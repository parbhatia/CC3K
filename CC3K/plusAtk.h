#ifndef _PLUS_ATK_H_
#define _PLUS_ATK_H_
#include "potion.h"

class PlusAttack: public Potion {
public:
    void beUsed(Player *whoFrom) override;
    ~PlusAttack();
};
#endif