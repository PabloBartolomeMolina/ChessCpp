#include "CPiece.h"

/* Basic methods, like constructor and destructor. */

/// <summary>
/// Public constructor to set up basic elements of the Board objects.
/// </summary>
CPiece::CPiece()
{
	cout << "Piece object has been created." << endl;
}

/// <summary>
/// Public destructor.
/// </summary>
CPiece::~CPiece()
{
	cout << "Piece object has been destroyed." << endl;
}

void CPiece::move()
{
	cout << "I am generic" << endl;
}