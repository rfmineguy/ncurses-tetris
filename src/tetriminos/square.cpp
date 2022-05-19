#include "square.h"

Square::Square()
:Square(1, 1) {}

Square::Square(int x)
    :Square(x, 1){};

Square::Square(int x, int y)
:Tetromino(x, y) {
    pieceShapeArr = {
    '#', '#', ' ', ' ',
    '#', '#', ' ', ' ',
    ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' '
    };
    pieceWidth = 2;
    pieceHeight = 2;
}

Square::~Square() {}

void Square::TurnPiece(int direction) {
    // doesn't need to turn
    return;
}

bool Square::WillTouchStaticPiece(int dx, int dy, char staticBoard[WIDTH_IN_PIECES][HEIGHT_IN_PIECES]) {
    if (staticBoard[pieceX][pieceY + 1 + dy] != ' ')
        return true;
    if (staticBoard[pieceX + 1][pieceY + 1 + dy] != ' ')
        return true;
    //move left into the right of another block
    if (dx < 0 && staticBoard[pieceX + pieceWidth + dx][pieceY] != ' ' && staticBoard[pieceX + pieceWidth + dx][pieceY + 1] != ' ')
        return true;

    //move right into the left of another block
    if (dx > 0 && staticBoard[pieceX + 1 + dx][pieceY] != ' ' && staticBoard[pieceX + 1 + dx][pieceY] != ' ')
        return true;
    return false;
}
