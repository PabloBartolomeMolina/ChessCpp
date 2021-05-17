#include "CQueen.h"

/* Basic methods, like constructor and destructor. */

/// <summary>
/// Public constructor to set up basic elements of the Board objects.
/// </summary>
CQueen::CQueen(bool color, string pos, int num)
{
	string named = "Nan";
	string idd = "Nan";
	if (color)
		named = "Qw";
	else
		named = "Qb";
	idd = named + to_string(num);
	this->id = idd;
	this->name = named;
	this->position = pos;
	this->type = "Queen";
	cout << "Queen object has been created." << endl;
}

/// <summary>
/// Public destructor.
/// </summary>
CQueen::~CQueen()
{
	cout << "Queen object has been destroyed." << endl;
}

bool CQueen::move(string origin, string movement)
{
	cout << "I am the QUEEN" << endl;

	bool ret = false;

	char colOri = origin[0];
	char rowOri = origin[1];
	char colDes = movement[0];
	char rowDes = movement[1];

	return ret;
}