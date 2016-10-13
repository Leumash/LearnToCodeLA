#include <iostream>
#include "board.h"

using namespace std;

Board::Board() {
    this->isWinner = false;
    for (int i=0; i<9; ++i) {
        board[i] = i + '0';
    }
}

bool Board::makeMove(char player, int pos) {
    if (!isdigit(board[pos])) {
        return false;
    }

    board[pos] = player;
    return true;
}

bool Board::isGameOver() {
    if (areEqual(0, 1, 2)
        || areEqual(3, 4, 5)
        || areEqual(6, 7, 8)

        || areEqual(0, 3, 6)
        || areEqual(1, 4, 7)
        || areEqual(2, 5, 8)

        || areEqual(0, 4, 8)
        || areEqual(2, 4, 6)) {
        this->isWinner = true;
        return true;
    }

    if (!isMoveAvailable()) {
        this->isWinner = false;
        return true;
    }

    this->isWinner = false;
    return false;
}

bool Board::isMoveAvailable() {
    for (int i=0; i<9; ++i) {
        if (isdigit(board[i])) {
            return true;
        }
    }

    return false;
}

bool Board::doesWinnerExist() {
    return this->isWinner;
}

char Board::getWinner() {
    return winner;
}

bool Board::areEqual(int a, int b, int c) {
    if (board[a] == board[b] && board[b] == board[c]) {
        winner = board[a];
        return true;
    }

    return false;
}

void Board::printBoard() {
    cout << "Board:" << endl;
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            cout << board[i*3 + j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

