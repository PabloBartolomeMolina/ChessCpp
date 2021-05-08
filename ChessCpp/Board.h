#pragma once
#include <iostream>
#include <chrono>
#include <random>

using namespace std;

class Board
{
private:
    char piecePlacement[8];
    string pieces[12];
public:
    Board();
    ~Board();

};