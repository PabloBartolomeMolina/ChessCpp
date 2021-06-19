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

bool CKnight::move(string origin, string movement)
{
	cout << "I am a KNIGHT" << endl;

	bool ret = false;

	char colOri = origin[0];
	char rowOri = origin[1];
	char colDes = movement[0];
	char rowDes = movement[1];



	return ret;
}