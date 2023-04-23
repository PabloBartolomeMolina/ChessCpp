#include "CRook.h"
#include "CBoard.h"

/* Basic methods, like constructor and destructor. */

/// <summary>
/// Public constructor to set up basic elements of the Board objects.
/// </summary>
CRook::CRook(bool color, string pos, int num)
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
	cout << "Rook object has been created." << std::endl;
}

/// <summary>
/// Public destructor.
/// </summary>
CRook::~CRook()
{
	cout << "Rook object has been destroyed." << std::endl;
}


/// <summary>
/// Check the plausability of the movement taking into account the old position and the new one.
/// </summary>
/// <param name="new_f">New file</param>
/// <param name="old_f">Old file</param>
/// <param name="new_c">New column</param>
/// <param name="old_c">Old column</param>
/// <returns></returns>
bool CRook::check_movement(char new_f, char old_f, char new_c, char old_c)
{
	if ((new_f == old_f) && (new_c != old_c))
	{
		// Horizontal move is possible for a rook.
		return true;
	}
	else if ((new_f != old_f) && (new_c == old_c))
	{
		// Vertical move is possible for a rook.
		return true;
	}
	else
	{
		// Other type of move is not possible for a rook.
		return false;
	}
}

bool CRook::move(string origin, string movement)
{
	cout << "I am a ROOK" << std::endl;

	bool ret = false;
	bool freeWay = false;

	char colOri = origin[0];
	char rowOri = origin[1];
	char colDes = movement[0];
	char rowDes = movement[1];

	if (colOri == colDes)			// Vertical movement check.
	{
		// This piece can arrive to the destination if the way to it is free.
		CBoard board = CBoard();
		for (int i = origin[1] + 1; i < movement[1] - 1; i++)
		{
			string mov = to_string(colOri) + to_string(i);
			freeWay = board.CheckPosition(mov);
			if (freeWay)
			{
				/* Continue to check.*/
				ret = true;
			}
			else
			{
				/* A piece is in the way, no possible to make the move*/
				ret = false;
				break;
			}
		}
	}
	else if ( rowOri == rowDes)		// Horizontal movement check.
	{
		// This piece can arrive to the destination if the way to it is free.
		CBoard board = CBoard();
		for (int i = origin[0] + 1; i < movement[0] - 1; i++)
		{
			freeWay = board.CheckPosition(movement);
			if (freeWay)
			{
				/* Continue to check.*/
				ret = true;
			}
			else
			{
				/* A piece is in the way, no possible to make the move*/
				ret = false;
				break;
			}
		}
	}
	else
	{
		// Movement is not possible for this piece.
		ret = false;
	}

	return ret;
}

/// <summary>
/// Method to check if the king has already been moved.
/// </summary>
/// <returns>TRUE if not yet moved. FALSE if already moved</returns>
bool CRook::firstMovement(string movement, bool color)
{
	bool result = false;

	if (movement == "0-0" && this->position == "h1" && this->color == color && this->firstMove)
	{
		result = true;
	}
	else if (movement == "0-0-0" && this->position == "a1" && this->color == color && this->firstMove)
	{
		result = true;
	}
	else if (movement == "0-0" && this->position == "h8" && this->color == color && this->firstMove)
	{
		result = true;
	}
	else if (movement == "0-0-0" && this->position == "a8" && this->color == color && this->firstMove)
	{
		result = true;
	}
	else
	{
		result = false;		// Not possible case.
	}

	return result;
}