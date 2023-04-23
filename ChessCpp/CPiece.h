#pragma once

#include <iostream>
#include <math.h>
#include <sstream>
#include "Defines.h"

;

class CPiece
{
public:
	 std::string id = "Nan";
	 std::string name = "Nan";
	 std::string position = "Nan";
	 std::string type = "Nan";
	bool color = 0;

	CPiece();
	~CPiece();
	void move();
};

