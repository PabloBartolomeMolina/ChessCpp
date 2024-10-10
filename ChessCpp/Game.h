#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game {
    Board chessBoard;
    bool isWhiteTurn;

public:
    Game();
    void startGame();
    void playerMove();
    void checkGameState();
};

#endif
