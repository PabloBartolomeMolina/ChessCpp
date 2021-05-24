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
	cout << "Rook object has been created." << endl;
}

/// <summary>
/// Public destructor.
/// </summary>
CRook::~CRook()
{
	cout << "Rook object has been destroyed." << endl;
}

bool CRook::move(string origin, string movement)
{
	cout << "I am a ROOK" << endl;

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