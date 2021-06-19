#pragma once

#include <iostream>
#include <math.h>
#include <sstream>
#include "Defines.h"

using namespace std;

class CPiece
{
public:
	string id = "Nan";
	string name = "Nan";
	string position = "Nan";
	string type = "Nan";
	bool color = 0;

	CPiece();
	~CPiece();
	void move();
};

