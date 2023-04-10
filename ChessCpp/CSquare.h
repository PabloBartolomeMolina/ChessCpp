#pragma once
#include <iostream>
#include <map>
#include "Defines.h"

using namespace std;

class CSquare
{
private:
    string piece;
    string color;
    int x, y;

public:
    CSquare(); 
    void setEmpty();
    void setPieceAndColor(string p, string c);
    string getPiece();
    string getColor();
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
};