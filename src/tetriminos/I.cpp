#include "I.h"

I::I()
:I(1, 1){}

I::I(int x)
:I(x, 1){}

I::I(int x, int y)
:Tetromino(x, y) {
    pieceShapeArr = {
    '#', ' ', ' ', ' ',
    '#', ' ', ' ', ' ',
    '#', ' ', ' ', ' ',
    '#', ' ', ' ', ' ' 
    };
    pieceWidth = 1;
    pieceHeight = 4;
}
I::~I() {}
 
//I should rotate between two states
//# -0
//# -4
//# -8
//# -12
//
//# # # # -3
void I::TurnPiece(int direction) {
    switch (direction) {
    case 0: break;
    case 1: break;
    default: break;
    }
}

bool I::WillTouchStaticPiece(int dx, int dy, char staticBoard[WIDTH_IN_PIECES][HEIGHT_IN_PIECES]) {
    int x = GetX();
    int y = GetY();
    if (staticBoard[x][y + pieceHeight + dy - 1] != ' ')
        return true;
    for (int i = 0; i < pieceHeight; i++) {
        if (staticBoard[x + dx][y + i] != ' ')
            return true;
    }
    return false;
}
