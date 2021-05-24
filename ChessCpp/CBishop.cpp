#include "CBishop.h"
#include "CBoard.h"

/* Basic methods, like constructor and destructor. */

/// <summary>
/// Public constructor to set up basic elements of the Board objects.
/// </summary>
CBishop::CBishop(bool color, string pos, int num)
{
	string named = "Nan";
	string idd = "Nan";
	if (color)
		named = "Bw";
	else
		named = "Bb";
	idd = named + to_string(num);
	this->id = idd;
	this->name = named;
	this->position = pos;
	this->type = "Bishop";
	cout << "Bishop object has been created." << endl;
}

/// <summary>
/// Public destructor.
/// </summary>
CBishop::~CBishop()
{
	cout << "Bishop object has been destroyed." << endl;
}


bool CBishop::move(string origin, string movement)
{
	cout << "I am a BISHOP" << endl;

	bool ret = false;
	bool freeWay = false;

	char colOri = origin[0];
	char rowOri = origin[1];
	char colDes = movement[0];
	char rowDes = movement[1];

	int intOri = (int)rowOri;
	int intDes = (int)rowDes;
	int differ = 0;

	// Check how far the bishop is moving.
	if (intOri < intDes)
		differ = intDes - intOri;
	else
		differ = intOri - intDes;

	// Take action depending on distance.
	if (differ == 1)
	{
		// Moving to an adyacent position, so no path to check.
		ret = true;
	}
	else
	{
		// This piece can arrive to the destination if the way to it is free.
		CBoard board = CBoard();
		// Moving to a further position, so need to check the path in between. Check depends on direction of movement.
		if (intOri < intDes)
		{
			int counter = 0;
			for (int i = (intOri + 1); i < intDes; i++)
			{
				// Check corresponding position of the diagonal to be done by the bishop.

				// Form the string for the position to check.
				char c = colOri;
				if (colOri < colDes)
				{
					c = c + counter;
				}
				else
				{
					c = c - counter;
				}
				string mov = "";
				mov.append(1, c);
				mov += to_string(i);

				freeWay = board.CheckPosition(mov);
				if (freeWay == false)
				{
					break;	// Once the path is blocked at one position, the move is not possible. No sense to continue checking.
				}

				counter++;		// Increment counter for columns.
			}
		}
		else
		{
			int counter = 0;
			for (int i = (intOri - 1); i > intDes; i--)
			{
				// Check corresponding position of the diagonal to be done by the bishop.

				// Form the string for the position to check.
				char c = colOri;
				if (colOri < colDes)
				{
					c = c + counter;
				}
				else
				{
					c = c - counter;
				}
				string mov = "";
				mov.append(1, c);
				mov += to_string(i);

				freeWay = board.CheckPosition(mov);
				if (freeWay == false)
				{
					break;	// Once the path is blocked at one position, the move is not possible. No sense to continue checking.
				}

				counter++;		// Increment counter for columns.
			}
		}
	}

	return ret;
}