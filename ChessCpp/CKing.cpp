#include "CKing.h"

/* Basic methods, like constructor and destructor. */

/// <summary>
/// Public constructor to set up basic elements of the Board objects.
/// </summary>
CKing::CKing(bool color, std::string pos, int num)
{
	std::string named = "Nan";
	std::string idd = "Nan";
	if (color)
		named = "Kw";
	else
		named = "Kb";
	idd = named + std::to_string(num);
	this->id = idd;
	this->name = named;
	this->position = pos;
	this->type = "King";
	std::cout << "King object has been created." << std::endl;
}

/// <summary>
/// Public destructor.
/// </summary>
CKing::~CKing()
{
	std::cout << "King object has been destroyed." << std::endl;
}

/// <summary>
/// Validity of movements of king.
/// </summary>
/// <param name="origin">Original position.</param>
/// <param name="movement">Destination.</param>
/// <param name="firstMove">First move is already done or not.</param>
/// <returns></returns>
bool CKing::move(std::string origin, std::string movement)
{
	std::cout << "I am the KING" << std::endl;

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

/// <summary>
/// Method to check if the king has already been moved.
/// </summary>
/// <returns>TRUE if not yet moved. FALSE if already moved</returns>
bool CKing::firstMovement()
{
	bool result = false;

	if (this->position == "e1" && this->color == true && this->firstMove == true)		// White king check.
	{
		result = true;
	}
	else if (this->position == "e8" && this->color == false && this->firstMove == true)		// Black king check.
	{
		result = true;
	}
	else
	{
		result = false;	// Not possible case.
	}

	return result;
}