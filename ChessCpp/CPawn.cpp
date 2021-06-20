#include "CPawn.h"

using namespace std;

/* Basic methods, like constructor and destructor. */

/// <summary>
/// Public constructor to set up basic elements of the Board objects.
/// </summary>
CPawn::CPawn(bool color, string pos, int num)
{
	string named = "Nan";
	string idd = "Nan";
	if (color)
		named = "pw";
	else
		named = "pb";
	idd = named + to_string(num);
	this->color = color;
	this->id = idd;
	this->name = named;
	this->position = pos; 
	this->type = "pawn";
	cout << "Pawn object has been created." << endl;
}

/// <summary>
/// Public destructor.
/// </summary>
CPawn::~CPawn()
{
	cout << "Pawn object has been destroyed." << endl;
}


/// <summary>
/// 
/// </summary>
/// <param name="movement"> Movement to do in string format. Already validated but need to check if the way is clear.</param>
/// <param name="moveType">1 to advance 1 position, 2 to advance 2 positions and 3 to eat a piece.</param>
/// <returns></returns>
bool CPawn::move(string origin, string movement)
{
	cout << "I am a PAWN" << endl;

	if (this->color)	// Debuging purposes.
		cout << "white pawn" << endl;

	bool ret = false;

	char colOri = origin[0];
	int rowOri = origin[1] - '0';
	char colDes = movement[0];
	int rowDes = movement[1] - '0';

	/* Check column difference. */
	int dif = abs(rowDes - rowOri);


	if (colOri == colDes)	// Same column.
	{
		if (dif == 1)	// Next row.
		{
			ret = simpleMove(origin, movement);
		}
		else if (dif == 2)	// Row 2 places away.
		{
			
		}
		else	// Further row. This case is not possible, just safety usecase.
		{
			ret = false;
		}
	}
	else if ((colOri == colDes + 1) || (colOri == colDes - 1))	// Adyacent column.
	{
		if (dif == 1)	// Next row.
		{
			ret = simpleMove(origin, movement);
		}
		else	// Further row. This case is not possible, just safety usecase.
		{
			ret = false;
		}
	}
	else	// Further column. This case is not possible, just safety usecase.
	{
		ret = false;
	}

	return ret;
}

/* PRIVATE methods of the class CPawn. */

/// <summary>
/// Perform all checks for advancing one single cell.
/// </summary>
/// <param name="origin">Origin position</param>
/// <param name="movement">Destination</param>
/// <returns></returns>
bool CPawn::simpleMove(string origin, string movement)
{
	bool ret = false;

	char colOri = origin[0];
	int rowOri = origin[1] - '0';
	char colDes = movement[0];
	int rowDes = movement[1] - '0';

	return ret;
}

/// <summary>
/// Check conditions to advance two positions. Only possible for the first move.
/// </summary>
/// <param name="origin">Origin position</param>
/// <param name="movement">Destination</param>
/// <returns></returns>
bool CPawn::doubleMove(string origin, string movement)
{
	bool ret = false;

	char colOri = origin[0];
	int rowOri = origin[1] - '0';
	char colDes = movement[0];
	int rowDes = movement[1] - '0';

	return ret;
}

/// <summary>
/// Checks for eating a piece.
/// </summary>
/// <param name="origin">Origin position</param>
/// <param name="movement">Destination</param>
/// <returns></returns>
bool CPawn::eat(string origin, string movement)
{
	bool ret = false;

	char colOri = origin[0];
	int rowOri = origin[1] - '0';
	char colDes = movement[0];
	int rowDes = movement[1] - '0';

	return ret;
}

/// <summary>
/// Checks for eating at passant.
/// </summary>
/// <param name="origin">Origin position</param>
/// <param name="movement">Destination</param>
/// <returns></returns>
bool CPawn::eatPassant(string origin, string movement)
{
	bool ret = false;

	char colOri = origin[0];
	int rowOri = origin[1] - '0';
	char colDes = movement[0];
	int rowDes = movement[1] - '0';

	return ret;
}