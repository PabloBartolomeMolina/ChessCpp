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

void CPawn::move()
{
	cout << "I am a PAWN" << endl;
}