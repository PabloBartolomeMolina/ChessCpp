#pragma once

#include <iostream>
#include <chrono>
#include <map>
#include <random>

using namespace std;

class Player
{
private:
	// 0 for black color and 1 for white color.
	bool color = 0;
	// 0 for no turn of movement and 1 for turn of movement.
	bool turn = 0;
	// By default it is for black pieces, to be changed if needed at creation of object.
	string pieces[8] = { "Rb", "Nb", "Bb", "Qb", "Kb", "Bb", "Nb", "Rb" };

public:
	Player(bool input = false);
	~Player();
};

