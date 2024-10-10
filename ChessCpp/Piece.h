#pragma once

#include <iostream>
#include <math.h>
#include <sstream>
#include "Defines.h"

class Piece
{
public:
	 std::string id = "Nan";
	 std::string name = "Nan";
	 std::string position = "Nan";
	 std::string type = "Nan";
	bool color = 0;

	Piece();
	~Piece();
	void move();
};

