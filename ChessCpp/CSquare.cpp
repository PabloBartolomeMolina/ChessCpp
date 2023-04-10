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

void CSquare::setPiece(Piece p)
{
	piece = p;
}

void CSquare::setColor(Color c)
{
	color = c;
}

Piece CSquare::getPiece()
{
	return piece;
}

Color CSquare::getColor()
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
