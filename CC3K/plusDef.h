#ifndef _PLUS_DEF_H_
#define _PLUS_DEF_H_
#include "potion.h"

class PlusDef: public Potion {
public:
    void beUsed(Player *whoFrom) override;
    ~PlusDef();
};
#endif
