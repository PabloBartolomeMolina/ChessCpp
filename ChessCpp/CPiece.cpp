#include "CPiece.h"

/* Basic methods, like constructor and destructor. */

/// <summary>
/// Public constructor to set up basic elements of the Board objects.
/// </summary>
CPiece::CPiece()
{
	std::cout << "Piece object has been created." << std::endl;
}

/// <summary>
/// Public destructor.
/// </summary>
CPiece::~CPiece()
{
	std::cout << "Piece object has been destroyed." << std::endl;
}

void CPiece::move()
{
	std::cout << "I am generic" << std::endl;
}