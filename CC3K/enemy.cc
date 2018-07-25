#include "enemy.h"
#include "player.h"
#include "object.h"
#include "drow.h"
#include "goblin.h"
#include "attack.h"
#include <string>
#include <iostream>
using namespace std;

Enemy::Enemy(double atk, double def, double hp): Character{atk, def, hp} {}

Enemy::~Enemy() {}

void Enemy::notify(Player* p) { 
    if (getHostile()) {                  //decide if attack here. check hostile
        p->beAttacked(this);
    } else {
        cout << "I am your friend" << endl;
    }
}

void Enemy::attack(Player *p) {
    int chance = rand() % 10 + 1;
    if (chance > p->getMissChance()) {
        double dmg = (-getAtk() * 100 / (100 + p->getDef()));
        p->changeHp(dmg);
        stringstream ss;
        if(p->getHp()<=0){
            ss << print() <<" kills PC" << ".";
            addAction(ss.str());
            //throw Attack{dmg, 0, Result::death};
        }
        else{
            // ss << printAttack(dmg);
            // addAction(ss.str());
            //throw Attack{dmg, whoTo->getHp(), Result::attack};
        } 
    } else {
       // throw Attack{0, whoTo->getHp(), Result::miss};
    }
}


void Enemy::attack(Drow *d) {
    int chance = rand()%10 + 1;
    if (chance > getMissChance()) {
        double dmg = -getAtk()*100/(100+d->getDef());
        d->changeHp(dmg);
        if(d->getHp() <= 0){
            throw Attack{dmg,0,Result::death};
        }
        else{
            throw Attack{dmg, d->getHp(), Result::attack}; 
        }
    }
    else{
        throw Attack{0, d->getHp(), Result::miss};
    }    
}

void Enemy::attack(Goblin *g) {
    int chance = rand()%10 + 1;
    if (chance > getMissChance()) {
        double dmg = -getAtk()*100/(100+g->getDef());
        g->changeHp(dmg);
        if(g->getHp() <= 0){
            throw Attack{dmg,0,Result::death};
        }
        else{
            throw Attack{dmg, g->getHp(), Result::attack}; 
        }
    }
    else{
        throw Attack{0, g->getHp(), Result::miss};
    }    
}

void Enemy::setHostile(bool n) {}