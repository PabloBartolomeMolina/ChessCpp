#include "CBishop.h"

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


bool CBishop::move(string movement)
{
	cout << "I am a BISHOP" << endl;
}