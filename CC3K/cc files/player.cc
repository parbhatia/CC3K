#include "player.h"

Player::Player( int atk, int def, int hp): Character{atk, def, hp}, gold{0}, merchant_hostile(false) {}
char Player::print() {
    return '@';
}
void Player::changeGold(int n) {
    gold += n;
}

int Player::getGold() {
    return gold;
}