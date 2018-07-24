#include "player.h"

Player::Player( double atk, double def, double hp): Character{atk, def, hp}, gold{0}, merchant_hostile(false) {}
char Player::print() {
    return '@';
}
void Player::changeGold(int n) {
    gold += n;
}

int Player::getGold() {
    return gold;
}