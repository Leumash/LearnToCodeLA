#ifndef _BOARD_H_
#define _BOARD_H_

class Board {
    public:
        Board();

        bool makeMove(char player, int pos);

        bool isGameOver();
        bool doesWinnerExist();
        char getWinner();
        void printBoard();
    private:
        bool areEqual(int,int,int);
        bool isMoveAvailable();
        char board[9];
        char winner;
        bool isWinner;
};

#endif
