#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "board.h"

class Player {
    public:
        Player(char);

        bool makeMove(Board*, int);
        char getPlayer();
    private:
        char p;
};

#endif
