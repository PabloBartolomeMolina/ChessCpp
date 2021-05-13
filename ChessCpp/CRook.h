#pragma once
#include <iostream>
#include "CPiece.h"

using namespace std;

class CRook : public CPiece
{
public:
	CRook();
	~CRook();
	void move();
};

