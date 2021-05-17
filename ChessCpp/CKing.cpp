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

bool CKing::move(string origin, string movement)
{
	cout << "I am the KING" << endl;

	bool ret = false;

	char colOri = origin[0];
	char rowOri = origin[1];
	char colDes = movement[0];
	char rowDes = movement[1];

	/* Check the columns validity. */
	if (colOri == columns[0] && (movement[0] == columns[0] || movement[0] == columns[1]))		// Column a.
		ret = true;
	else if (colOri == columns[1] && (movement[0] == columns[0] || movement[1] == columns[1] || movement[1] == columns[2]))	// Column b.
		ret = true;
	else if (colOri == columns[2] && (movement[0] == columns[1] || movement[1] == columns[2] || movement[1] == columns[3]))	// Column c.
		ret = true;
	else if (colOri == columns[3] && (movement[0] == columns[2] || movement[1] == columns[3] || movement[1] == columns[4]))	// Column d.
		ret = true;
	else if (colOri == columns[4] && (movement[0] == columns[3] || movement[1] == columns[4] || movement[1] == columns[5]))	// Column e.
		ret = true;
	else if (colOri == columns[5] && (movement[0] == columns[4] || movement[1] == columns[5] || movement[1] == columns[6]))	// Column f.
		ret = true;
	else if (colOri == columns[6] && (movement[0] == columns[5] || movement[1] == columns[6] || movement[1] == columns[7]))	// Column g.
		ret = true;
	else if (colOri == columns[7] && (movement[0] == columns[6] || movement[0] == columns[7]))	// Column h.
		ret = true;

	return ret;
}