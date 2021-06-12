#pragma once
#include <iostream>
#include <map>
#include "Defines.h"

using namespace std;

class CBoard
{
private:
    /* Two pieces of each type, following the next code:
     * b = black piece   //   w = white piece
     * p = pawn   //   R = Rook   //  N = Knight
     * B = Bishop   //   Q = Queen   //  K = King */
    string whitePieces[8] = { "Rw", "Nw", "Bw", "Qw", "Kw", "Bw", "Nw", "Rw" };
    string blackPieces[8] = { "Rb", "Nb", "Bb", "Qb", "Kb", "Bb", "Nb", "Rb" };

    /* Arrays to store the positions for each player. Initialized with the initial positions. */
    string whitePositions[16] = { "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1",
                                  "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2" };
    string BlackPositions[16] = { "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8",
                                  "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7" };
   
    /* Columns names from the POV of each player with the adequate formating to be printed on console. */
    string colsWhite = "      a      b      c      d      e      f      g      h   ";
    string colsBlack = "      h      g      f      e      d      c      b      a   ";

    /* Horizontal separator for board and empty rows. */
    string horizontal = "    ______ ______ ______ ______ ______ ______ ______ ______ ";
    string rowEmpty = "|      |      |      |      |      |      |      |      |";
    string dSpace = "  |";
    /* Rows with initial position. */
    string row1 = "";
    string row2 = "";
    string row3 = "";
    string row4 = "";
    string row5 = "";
    string row6 = "";
    string row7 = "";
    string row8 = "";

    
    void initPlace();

public:
    CBoard();
    ~CBoard();
    bool CheckPosition(string position);
    string placePieces(string origin, string destination);
    void showBoard(bool player = 1);
};