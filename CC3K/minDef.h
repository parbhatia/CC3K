#ifndef _MIN_DEF_H_
#define _MIN_DEF_H_
#include "potion.h"

class MinDef: public Potion {
public:
    void beUsed(Player *whoFrom) override;
    ~MinDef();
};
#endif
