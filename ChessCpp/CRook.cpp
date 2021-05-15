#include "CRook.h"

/* Basic methods, like constructor and destructor. */

/// <summary>
/// Public constructor to set up basic elements of the Board objects.
/// </summary>
CRook::CRook(bool color, string pos=, int num)
{
	string named = "Nan";
	string idd = "Nan";
	if (color)
		named = "Rw";
	else
		named = "Rb";
	idd = named + to_string(num);
	this->id = idd;
	this->name = named;
	this->position = pos;
	this->type = "Rook";
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