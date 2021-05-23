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

/// <summary>
/// Validity of movements of king.
/// </summary>
/// <param name="origin">Original position.</param>
/// <param name="movement">Destination.</param>
/// <param name="firstMove">First move is already done or not.</param>
/// <returns></returns>
bool CKing::move(string origin, string movement)
{
	cout << "I am the KING" << endl;

	bool ret = false;		// Flag to return.

	char colOri = tolower(origin[0]);		// Column of origin.
	int rowOri = origin[1] - '0';			// Row of origin.
	char colDes = tolower(movement[0]);		// Column of destination.
	int rowDes = movement[1] - '0';			// Row of destination.

	// Check is done according to the origin column as initial reference.
	switch (colOri)
	{
	case 'a':	// Check movement's validity from columns a, any row.
		if (colDes == 'a' && (rowDes == (rowOri + 1) || rowDes == (rowOri - 1)))
			ret = true;
		else if (colDes == 'b' && (rowDes == (rowOri + 1) || rowDes == (rowOri - 1) || rowDes == rowOri))
			ret = true;
		else
			ret = false;
		break;
	case 'b':	// Check movement's validity from columns b, any row.
	case 'c':	// Check movement's validity from columns c, any row.
	case 'd':	// Check movement's validity from columns d, any row.
	case 'e':	// Check movement's validity from columns e, any row.
	case 'f':	// Check movement's validity from columns f, any row.
	case 'g':	// Check movement's validity from columns g, any row.
		if (((int)colDes == (int)colOri) && (rowDes == (rowOri + 1) || rowDes == (rowOri - 1)))
			ret = true;
		else if (((int)colDes == ((int)colOri - 1) || (int)colDes == ((int)colOri + 1)) && (rowDes == (rowOri + 1) || rowDes == (rowOri - 1) || rowDes == rowOri))
			ret = true;
		else
			ret = false;

		// Castling case.
		if (firstMove && colOri == 'e' && (colDes == 'b' || colDes == 'g'))
			ret = true;
		else
			ret = false;
		break;
	case 'h':	// Check movement's validity from columns h, any row.
		if (colDes == 'h' && (rowDes == (rowOri + 1) || rowDes == (rowOri - 1)))
			ret = true;
		else if (colDes == 'g' && (rowDes == (rowOri + 1) || rowDes == (rowOri - 1) || rowDes == rowOri))
			ret = true;
		else
			ret = false;
		break;
	default:
		/* If not in range, it is managed before. Just return a false flag in this case to add safety step. */
		ret = false;
		break;
	}

	return ret;
}