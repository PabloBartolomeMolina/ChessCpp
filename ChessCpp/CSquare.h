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


public:
    
};