#pragma once

#include <iostream>
#include <map>
#include "Defines.h"

using namespace std;

class CPiece
{
private:
	map<string, string> piece = { {"NaN", "Nan" } };
public:
	
	CPiece();
	~CPiece();
};

