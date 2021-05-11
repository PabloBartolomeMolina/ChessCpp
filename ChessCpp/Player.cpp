#include "Player.h"

/* Basic methods, like constructor and destructor. */

/// <summary>
/// Public constructor to set up basic elements of the Board objects.
/// </summary>
Player::Player(bool input)
{
    color = input;
    // Set color of instance.
    if (color)
        cout << "Player white has been created." << endl;
    else
        cout << "Player black has been created." << endl;
}

/// <summary>
/// Public destructor.
/// </summary>
Player::~Player()
{
    if (color)
        cout << "Player white has been created." << endl;
    else
        cout << "Player black has been created." << endl;
}