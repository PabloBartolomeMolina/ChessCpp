#include "Piece.h"

/* Basic methods, like constructor and destructor. */

/// <summary>
/// Public constructor to set up basic elements of the Board objects.
/// </summary>
Piece::Piece()
{
	std::cout << "Piece object has been created." << std::endl;
}

/// <summary>
/// Public destructor.
/// </summary>
Piece::~Piece()
{
	std::cout << "Piece object has been destroyed." << std::endl;
}

void Piece::move()
{
	std::cout << "I am generic" << std::endl;
}