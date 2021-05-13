#include "CRook.h"

/* Basic methods, like constructor and destructor. */

/// <summary>
/// Public constructor to set up basic elements of the Board objects.
/// </summary>
CRook::CRook()
{
	cout << "Rook object has been created." << endl;
}

/// <summary>
/// Public destructor.
/// </summary>
CRook::~CRook()
{
	cout << "Rook object has been destroyed." << endl;
}

void CRook::move()
{
	cout << "I am a ROOK" << endl;
}