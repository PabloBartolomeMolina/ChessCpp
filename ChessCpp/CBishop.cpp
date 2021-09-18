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


/// <summary>
/// Check the plausability of the movement taking into account the old position and the new one.
/// </summary>
/// <param name="new_f">New file</param>
/// <param name="old_f">Old file</param>
/// <param name="new_c">New column</param>
/// <param name="old_c">Old column</param>
/// <returns></returns>
bool CBishop::check_movement(char new_f, char old_f, char new_c, char old_c)
{
	if (abs((int)new_f - (int)old_f) == abs((int)new_c - (int)old_c))
	{
		// Diagonal move is possible for a bishop.
		return true;
	}
	else
	{
		// Other type of move is not possible for a bishop.
		return false;
	}
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

	differ = abs(intOri - intDes);

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