#include "CKnight.h"

/* Basic methods, like constructor and destructor. */

/// <summary>
/// Public constructor to set up basic elements of the Board objects.
/// </summary>
CKnight::CKnight(bool color, string pos, int num)
{
	string named = "Nan";
	string idd = "Nan";
	if (color)
		named = "Nw";
	else
		named = "Nb";
	idd = named + to_string(num);
	this->id = idd;
	this->name = named;
	this->position = pos;
	this->type = "Knight";
	cout << "Knight object has been created." << endl;
}

/// <summary>
/// Public destructor.
/// </summary>
CKnight::~CKnight()
{
	cout << "Knight object has been destroyed." << endl;
}