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
    int x = GetX();
    int y = GetY();
    if (staticBoard[x][y + 1 + dy] != ' ')
        return true;
    if (staticBoard[x + 1][y + 1 + dy] != ' ')
        return true;
    //move left into the right of another block
    if (dx < 0) {
        for (int j = 0; j < pieceHeight; j++) {
            if (staticBoard[x + dx][y + j] != ' ')
                return true;
        }
    }     
    //move right into the left of another block
    if (dx > 0 && staticBoard[x + pieceWidth + dx][y] != ' ')
        return true;
    return false;
}
