#include "player.h"

Player::Player( int atk, int def, int hp): Character{atk, def, hp}, gold{0}, merchant_hostile(false) {}
char Player::print() {
    return '@';
}
