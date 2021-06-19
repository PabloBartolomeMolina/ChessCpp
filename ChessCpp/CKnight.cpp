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
	int rowOri = origin[1] - '0';
	char colDes = movement[0];
	int rowDes = movement[1] - '0';

	/* Check column difference. */
	int dif = abs(rowDes - rowOri);

	if (dif == 1)	// 1 row of difference means 2 columns of difference.
	{
		if ((colOri == colDes + 2) || (colOri == colDes - 2))
		{
			ret = true;
		}
		else
		{
			cout << "Movement not possible for this piece." << endl;
			ret = false;
		}
	}
	else if (dif == 2)	// 2 rows of difference means s column of difference.
	{
		if ((colOri == colDes + 1) || (colOri == colDes - 1))
		{
			ret = true;
		}
		else
		{
			cout << "Movement not possible for this piece." << endl;
			ret = false;
		}
	}
	else	// No other options are possible for this piece.
	{
		cout << "Movement not possible for this piece." << endl;
		ret = false;
	}


	return ret;
}