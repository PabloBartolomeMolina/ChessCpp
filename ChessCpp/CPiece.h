#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include "Defines.h"

using namespace std;

class CPiece
{
public:
	string id = "Nan";
	string name = "Nan";
	string position = "Nan";
	string type = "Nan";

	CPiece();
	~CPiece();
	void move();
};

