#pragma once
#include <iostream>
#include <map>
#include "Defines.h"

using namespace std;

enum Piece {KIG, QUEEN, ROOK, KNIGHT, BISHOP, PAWN, EMPTY};
enum Color {WHITE, BLACK, NONE};

class CSquare
{
private:
    Piece piece;
    Color color;
    int x, y;

public:
    CSquare(); 
    void setEmpty();
    void setPiece();
    void setColor();
    Piece getPiece();
    Color getColor();
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
};