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

/// <summary>
/// Check the plausability of the movement taking into account the old position and the new one.
/// </summary>
/// <param name="new_f">New file</param>
/// <param name="old_f">Old file</param>
/// <param name="new_c">New column</param>
/// <param name="old_c">Old column</param>
/// <returns></returns>
bool CQueen::check_movement(char new_f, char old_f, char new_c, char old_c)
{
	if (abs((int)new_f - (int)old_f) == abs((int)new_c - (int)old_c))
	{
		// Diagonal move is possible for a queen.
		return true;
	}
	else if ((new_f == old_f) && (new_c != old_c))
	{
		// Horizontal move is possible for a queen.
		return true;
	}
	else if ((new_f != old_f) && (new_c == old_c))
	{
		// Vertical move is possible for a queen.
		return true;
	}
	else
	{
		// Other type of move is not possible for a queen.
		return false;
	}
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