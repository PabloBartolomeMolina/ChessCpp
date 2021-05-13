#pragma once
#include <iostream>
#include "CPiece.h"

using namespace std;

class CKnight : public CPiece
{
public:
	CKnight();
	~CKnight();
	void move();
};

