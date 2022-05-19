#include "T.h"

T::T()
:T(1, 1) {}

T::T(int x)
    :T(x, 1){}

T::T(int x, int y)
:Tetromino(x, y) {
    pieceShapeArr = {
    '#', '#', '#', ' ',
    ' ', '#', ' ', ' ',
    ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ',
    };
    pieceWidth = 3;
    pieceHeight = 2;
    rotation = 0;
}

T::~T() {}

void T::TurnPiece(int direction) {
    switch (direction % 4) {
    case 0: break;
    case 1: break;
    case 2: break;
    case 3: break;
    }
}

bool T::WillTouchStaticPiece(int dx, int dy, char staticBoard[WIDTH_IN_PIECES][HEIGHT_IN_PIECES]) {

    return false;
}
