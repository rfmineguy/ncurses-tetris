#include "L.h"

L::L()
:L(0, 0) {}

L::L(int x)
:L(x, 0){}

L::L(int x, int y)
:Tetromino(x, y){
    pieceShapeArr = {
    '#', ' ', ' ', ' ',
    '#', ' ', ' ', ' ',
    '#', ' ', ' ', ' ',
    '#', '#', ' ', ' '
    };
    pieceWidth = 2;
}

L::~L() {}

void L::TurnPiece(int direction) {
    switch (direction % 4) {
    case 0: {
            pieceShapeArr = {

            };
            break;
        }
    case 1: break;
    case 2: break;
    case 3: break;
    }
}

bool L::WillTouchStaticPiece(int dx, int dy, char staticBoard[WIDTH_IN_PIECES][HEIGHT_IN_PIECES]) {
    if (staticBoard[pieceX][pieceY + pieceHeight + dy - 1] != ' ') {
        return true;
    }
    if (staticBoard[pieceX + 1 + dx][pieceY + pieceHeight + dy - 1] != ' ')
        return true;
    for (int i = 0; i < pieceHeight; i++) {
        if (staticBoard[pieceX + dx][pieceY + i] != ' ')
            return true;
    }
    return false;
}
