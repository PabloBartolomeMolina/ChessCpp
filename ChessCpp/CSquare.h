#pragma once
#include <iostream>
#include <map>
#include "Defines.h"

using namespace std;

class CSquare
{
private:
    Piece piece;
    Color color;
    int x, y;

public:
    CSquare(); 
    void setEmpty();
    void setPiece(Piece p);
    void setColor(Color p);
    Piece getPiece();
    Color getColor();
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
};