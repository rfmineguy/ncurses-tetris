#include "T.h"

T::T()
:T(1, 1) {}

T::T(int x)
    :T(x, 1){}

T::T(int x, int y)
:Tetromino(x, y) {
    TurnPiece(0);
}

T::~T() {}

void T::TurnPiece(int direction) {
    orientation += direction;
    orientation %= 4;
    switch (orientation) {
    case 0: 
        pieceShapeArr = {
        '#', '#', '#', ' ',
        ' ', '#', ' ', ' ',
        ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' '
        };
        pieceWidth = 3;
        pieceHeight = 2;
        break;
    case 1: 
        pieceShapeArr = {
        ' ', '#', ' ', ' ',
        '#', '#', ' ', ' ',
        ' ', '#', ' ', ' ',
        ' ', ' ', ' ', ' '
        };
        pieceWidth = 2;
        pieceHeight = 3;
        break;
    case 2: 
        pieceShapeArr = {
        ' ', '#', ' ', ' ',
        '#', '#', '#', ' ',
        ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' '
        };
        pieceWidth = 3;
        pieceHeight = 2;
        break;
    case 3: 
        pieceShapeArr = {
        '#', ' ', ' ', ' ',
        '#', '#', ' ', ' ',
        '#', ' ', ' ', ' ',
        ' ', ' ', ' ', ' '
        };
        pieceWidth = 2;
        pieceHeight = 3;
        break;
    }
}

bool T::WillTouchStaticPiece(int dx, int dy, char staticBoard[WIDTH_IN_PIECES][HEIGHT_IN_PIECES]) {

    return false;
}
