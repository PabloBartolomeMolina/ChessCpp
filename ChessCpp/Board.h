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
    map<string, string> piecePlacementWhite{ {"pw1", "a2"}, {"pw2", "b2"}, {"pw3", "c2"}, {"pw4", "d2"}, {"pw5", "e2"}, {"pw6", "f2"}, {"pw7", "g2"}, {"pw8", "h2"},
                                             {"Rw1", "a1"}, {"Rw2", "h1"}, {"Nw1", "b1"}, {"Nw2", "g1"}, {"Bw1", "c1"}, {"Bw2", "f1"}, {"Qw", "f1"}, {"Kw", "e1"}};
    /* Map with positions of black pieces. Values corresponding to initial placement.*/
    map<string, string> piecePlacementBlack{ {"pb1", "a7"}, {"pb2", "b7"}, {"pb3", "c7"}, {"pb4", "d7"}, {"pb5", "e7"}, {"pb7", "f7"}, {"pb7", "g7"}, {"pb7", "h7"},
                                             {"Rb1", "a8"}, {"Rb2", "h8"}, {"Nb1", "b8"}, {"Nb2", "g8"}, {"Bb1", "c8"}, {"Bb2", "f8"}, {"Qb", "f8"}, {"Kb", "e8"} };
    /* Two pieces of each type, following the next code:
    * b = black piece   //   w = white piece
    * p = pawn   //   R = Rook   //  N = Knight
    * B = Bishop   //   Q = Queen   //  K = King */
    string pieces[12] = { "pw", "pb", "Rw", "Rb", "Nw", "Nb", "Bw", "Bb", "Qw", "Qb", "Kw", "Kb" };

    /* Columns names from the POV of each player with the adequate formating to be printed on console. */
    string colsWhite = "      a     b     c     d     e     f     g     h   ";
    string colsBlack = "      h     g     f     e     d     c     b     a   ";

    /* Horizontal separator for board and empty rows. */
    string horizontal = "    ______ ______ ______ ______ ______ ______ ______ ______ ";
    string rowEmpty = "|      |      |      |      |      |      |      |      |";
    /* Rows with initial position. */
    string row1 = "";
    string row2 = "";
    string row3 = "";
    string row4 = "";
    string row5 = "";
    string row6 = "";
    string row7 = "";
    string row8 = "";

    void initialPieces(bool initial);
    void initPlace();

public:
    Board();
    ~Board();
    void showBoard();
};