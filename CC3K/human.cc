#include "human.h"
#include "attack.h"
#include "goblin.h"
#include "drow.h"
#include "gold.h"
char Human::print(){
    return 'H';
}

Human::Human() : Enemy{20, 20, 140} {}

void Human::beAttacked(Object* whoFrom){
    whoFrom->attack(this);
}

Object* Human::spawn() {
    return new Gold{2};
}

// void Human::attack(Goblin* g){
//     double dmg = (-getAtk()*100/(100+g->getDef()));
//     int chance = rand()%10 + 1;
//     if (chance > getMissChance()) {
//         g->changeHp(dmg);
//         if(g->getHp()<=0){
//             throw Attack{dmg, 0, Result::death};
//         }
//     }
//     else {
//         dmg = 0;
//     }
//     Character::storeAction(dmg, print(), 'P', g->getHp);
// }

// void Human::attack(Drow *h) {
//     double chance = rand() % 10 + 1;
//     double dmg = (-getAtk() * 100 / (100 + h->getDef()));
//     if (chance > h->getMissChance()) {
//         h->changeHp(dmg);
//         if(h->getHp()<=0){
//             throw Attack{dmg, 0, Result::death};
//         } 
//     }
//     else {
//         dmg = 0;
//     }
//     Character::storeAction(dmg, print(), 'P', h->getHp);
// }
