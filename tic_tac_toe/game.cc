#include <iostream>
#include "player.h"
#include "board.h"

using namespace std;

class Game {
    public:
        Game();
        void playTicTacToe();
    private:
        void gameLoop();
        void printGame();
        bool isOver();
        void printResult();
        void switchCurrentPlayer();
        int getPlayerMove();

        Board* board;
        Player* player1;
        Player* player2;
        Player* currentPlayer;

};

int main() {
    Game game;

    game.playTicTacToe();
    return 0;
}

Game::Game() {
    board = new Board();
    player1 = new Player('X');
    player2 = new Player('O');
    currentPlayer = player1;
}

void Game::playTicTacToe() {
    while (!isOver()) {
        gameLoop();
    }

    printResult();
}

void Game::gameLoop() {
    printGame();

    while (true) {
        int move = getPlayerMove();

        if (currentPlayer->makeMove(board, move)) {
            switchCurrentPlayer();
            break;
        } else {
            cout << "That is an invalid move." << endl;
        }
    }
}

void Game::switchCurrentPlayer() {
    currentPlayer = currentPlayer == player1 ? player2 : player1;
}

int Game::getPlayerMove() {
    int move;
    char player = currentPlayer->getPlayer();

    cout << "Please make a move player " << player << " (0-8):" << endl;
    cin >> move;
    cout << endl;
    return move;
}

bool Game::isOver() {
    return this->board->isGameOver();
}

void Game::printResult() {
    printGame();

    if (board->doesWinnerExist()) {
        cout << "Winner is Player " << board->getWinner() << endl;
    } else {
        cout << "There is no winner" << endl;
    }
}

void Game::printGame() {
    board->printBoard();
}

