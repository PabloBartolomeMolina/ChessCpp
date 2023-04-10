#include "CSquare.h"

CSquare::CSquare()
{
	piece = EMPTY;
	color = NONE;
}

void CSquare::setEmpty()
{
	piece = EMPTY;
	color = NONE;
}

void CSquare::setPieceAndColor(string p, string c)
{
	piece = p;
	color = c;
}

string CSquare::getPiece()
{
	return piece;
}

string CSquare::getColor()
{
	return color;
}

void CSquare::setX(int x)
{
	this->x = x;
}

void CSquare::setY(int y)
{
	this->y = y;
}

int CSquare::getX()
{
	return x;
}

int CSquare::getY()
{
	return y;
}
