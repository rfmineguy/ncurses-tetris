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
    orientation += direction;
    orientation %= 2;
    switch (orientation) {
    case 0: {
            pieceShapeArr = {
                '#', ' ', ' ', ' ',
                '#', ' ', ' ', ' ',
                '#', ' ', ' ', ' ',
                '#', ' ', ' ', ' ',
            };
            pieceWidth = 1;
            pieceHeight = 4;
            break;
        }
    case 1: {
            pieceShapeArr = {
                '#', '#', '#', '#',
                ' ', ' ', ' ', ' ',
                ' ', ' ', ' ', ' ',
                ' ', ' ', ' ', ' ',
            };
            pieceWidth = 4;
            pieceHeight = 1;
            break;
        }
break;
    default: break;
    }
}

bool I::WillTouchStaticPiece(int dx, int dy, char staticBoard[WIDTH_IN_PIECES][HEIGHT_IN_PIECES]) {
    int x = GetX();
    int y = GetY();

    //collision based on orientation
    switch (orientation) {
        case 0: {
                    for (int j = 0; j < pieceHeight; j++) {
                        if (staticBoard[x + dx][y + j] != ' ')
                            return true;
                    }
                    if (staticBoard[x + dx][y + pieceHeight + dy - 1] != ' ')
                        return true;
                    break;
                }
        case 1: {
                    for (int j = 0; j < pieceWidth; j++) {
                        if (staticBoard[x + j + dx][y + dy] != ' ')
                            return true;
                    }
                }
    }
    return false;
}
