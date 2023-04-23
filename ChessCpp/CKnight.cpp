#include "CKnight.h"

/* Basic methods, like constructor and destructor. */

/// <summary>
/// Public constructor to set up basic elements of the Board objects.
/// </summary>
CKnight::CKnight(bool color, std::string pos, int num)
{
	std::string named = "Nan";
	std::string idd = "Nan";
	if (color)
		named = "Nw";
	else
		named = "Nb";
	idd = named + std::to_string(num);
	this->id = idd;
	this->name = named;
	this->position = pos;
	this->type = "Knight";
	std::cout << "Knight object has been created." << std::endl;
}

/// <summary>
/// Public destructor.
/// </summary>
CKnight::~CKnight()
{
	std::cout << "Knight object has been destroyed." << std::endl;
}

/// <summary>
/// Check the plausability of the movement taking into account the old position and the new one.
/// </summary>
/// <param name="new_f">New file</param>
/// <param name="old_f">Old file</param>
/// <param name="new_c">New column</param>
/// <param name="old_c">Old column</param>
/// <returns></returns>
bool CKnight::check_movement(char new_f, char old_f, char new_c, char old_c)
{
	if ((abs((int)new_f - (int)old_f) == 1) && (abs((int)new_c - (int)old_c) == 2))
	{
		// Correct move is possible for a knight.
		return true;
	}
	else if ((abs((int)new_f - (int)old_f) == 2) && (abs((int)new_c - (int)old_c) == 1))
	{
		// Correct move is possible for a knight.
		return true;
	}
	else
	{
		// Other type of move is not possible for a knight.
		return false;
	}
}

bool CKnight::move(std::string origin, std::string movement)
{
	std::cout << "I am a KNIGHT" << std::endl;

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
			std::cout << "Movement not possible for this piece." << std::endl;
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
			std::cout << "Movement not possible for this piece." << std::endl;
			ret = false;
		}
	}
	else	// No other options are possible for this piece.
	{
		std::cout << "Movement not possible for this piece." << std::endl;
		ret = false;
	}


	return ret;
}