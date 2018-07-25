#include "player.h"
#include "halfling.h"
#include "dwarf.h"
#include "attack.h"
using namespace std;

Player::Player( double atk, double def, double hp): Character{atk, def, hp}, gold{0}, merchant_hostile{false} {}
char Player::print() {
    return '@';
}
void Player::changeGold(int n) {
    gold += n;
}

int Player::getGold() {
    return gold;
}

void Player::notify(Player* p) {}

void Player::attack(Halfling *h) {
    int chance = rand() % 10 + 1;
    if (chance > 5) {   // Halfling has 50% chance to cause PC to miss.
        double dmg = (-getAtk() * 100 / (100 + h->getDef()));
        h->changeHp(dmg);
        if(h->getHp()<=0){
            //throw Attack{dmg, 0, Result::death};
        } else {
            //throw Attack{dmg, h->getHp(), Result::attack};
        }
    } else {
        //throw Attack{0, h->getHp(), Result::miss};
    }
}


void Player::attack(Dwarf *d) {
    int chance = rand() % 10 + 1;
    if (chance > getMissChance()) {
        double dmg = (-getAtk() * 100 / (100 + d->getDef()));
        d->changeHp(dmg);
        stringstream ss;
        if(d->getHp()<=0){
            ss << "PC kills " << d->print() << ".";
            addAction(ss.str());
            //throw Attack{dmg, 0, Result::death};
        } else {
            //ss << printAttack(dmg);
            addAction(ss.str());
            //throw Attack{dmg, d->getHp(), Result::attack};
        }
    } else {
        throw Attack{0, d->getHp(), Result::miss};
    }
}

void Player::attack(Enemy *e) {
    int chance = rand() % 10 + 1;
    if (chance > e->getMissChance()) {
        double dmg = (-getAtk() * 100 / (100 + e->getDef()));
        e->changeHp(dmg);
        stringstream ss;
        if(e->getHp()<=0){
            ss << "PC kills " << e->print() << ".";
            addAction(ss.str());
            //throw Attack{dmg, 0, Result::death};
        }
        else{
            // ss << printAttack(dmg);
            // addAction(ss.str());
            //throw Attack{dmg, whoTo->getHp(), Result::attack};
        }
        e->setHostile(true); //only need to set hostile for merchant and dragon 
    } else {
       // throw Attack{0, whoTo->getHp(), Result::miss};
    }
}
