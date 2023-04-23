#pragma once
#include <iostream>
#include <map>
#include "Defines.h"

class CSquare
{
private:
    int piece;
    int color;
    int x, y;

public:
    CSquare(); 
    void setEmpty();
    void setPieceAndColor(int p, int c);
    int getPiece();
    int getColor();
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
};