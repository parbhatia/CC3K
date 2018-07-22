#include "player.h"

Player::Player( int atk=10, int def=5, int hp=100): Character{atk, def, hp}, gold{0}, merchant_hostile(false) {}
char Player::print() {
    return '@';
}