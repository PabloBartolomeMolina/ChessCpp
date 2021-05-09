#pragma once
#include <iostream>
#include <chrono>
#include <random>

using namespace std;

class Board
{
private:
    char piecePlacement[8] = { ' ' };
    /* Two pieces of each type, following the next code:
    * b = black piece   //   w = white piece
    * p = pawn   //   R = Rook   //  N = Knight
    * B = Bishop   //   Q = Queen   //  K = King */
    string pieces[12] = { "pw", "pb", "Rw", "Rb", "Nw", "Nb", "Bw", "Bb", "Qw", "Qb", "Kw", "Kb" };
    void placePieces(bool initial);

public:
    Board();
    ~Board();
    void showBoard();
};