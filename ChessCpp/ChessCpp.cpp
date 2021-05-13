// ChessCpp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "CBoard.h"
#include "CPlayer.h"


/// <summary>
/// Function to manage the basic logic of the program.
/// </summary>
void basicLogic()
{
    // Creation of board and both players.
    CBoard board = CBoard();
    CPlayer whitePlayer = CPlayer(true);
    CPlayer blackPlayer = CPlayer(false);

    // Show board.
    board.showBoard(1);     // Board view for white player.
    board.showBoard(0);     // Board view for black player.
}

/// <summary>
/// Main function, the entry point of the program.
/// </summary>
/// <returns></returns>
int main()
{
    cout << initialMessage << endl << endl;
    basicLogic();
}


class Rectangle {
    int width, height;
public:
    Rectangle(int, int);
    int area() { return (width * height); }
};

Rectangle::Rectangle(int a, int b) {
    width = a;
    height = b;
}
/*
int main() {
    Rectangle rect(3, 4);
    Rectangle rectb(5, 6);
    cout << "rect area: " << rect.area() << endl;
    cout << "rectb area: " << rectb.area() << endl;
    return 0;
}*/