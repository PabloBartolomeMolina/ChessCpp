#include "CKing.h"

/* Basic methods, like constructor and destructor. */

/// <summary>
/// Public constructor to set up basic elements of the Board objects.
/// </summary>
CKing::CKing(bool color, string pos, int num)
{
	string named = "Nan";
	string idd = "Nan";
	if (color)
		named = "Kw";
	else
		named = "Kb";
	idd = named + to_string(num);
	this->id = idd;
	this->name = named;
	this->position = pos;
	this->type = "King";
	cout << "King object has been created." << endl;
}

/// <summary>
/// Public destructor.
/// </summary>
CKing::~CKing()
{
	cout << "King object has been destroyed." << endl;
}

bool CKing::move(string movement)
{
	cout << "I am the KING" << endl;
}