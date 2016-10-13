#include "player.h"
#include "board.h"

Player::Player(char p) {
    this->p = p;
}

char Player::getPlayer() {
    return this->p;
}

bool Player::makeMove(Board* board, int pos) {
    return board->makeMove(this->p, pos);
}

