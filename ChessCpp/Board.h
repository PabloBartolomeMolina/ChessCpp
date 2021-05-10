#pragma once
#include <iostream>
#include <chrono>
#include <map>
#include <random>

using namespace std;

class Board
{
private:
    /* Map with positions of white pieces. Values corresponding to initial placement.*/
    string whitePieces[8] = { "Rw", "Nw", "Bw", "Qw", "Kw", "Bw", "Nw", "Rw" };
    string blackPieces[8] = { "Rb", "Nb", "Bb", "Qb", "Kb", "Bb", "Nb", "Rb" };
    /* Two pieces of each type, following the next code:
    * b = black piece   //   w = white piece
    * p = pawn   //   R = Rook   //  N = Knight
    * B = Bishop   //   Q = Queen   //  K = King */
    string pieces[12] = { "pw", "pb", "Rw", "Rb", "Nw", "Nb", "Bw", "Bb", "Qw", "Qb", "Kw", "Kb" };

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

    void placePieces(bool initial);
    void initPlace();

public:
    Board();
    ~Board();
    void showBoard();
};