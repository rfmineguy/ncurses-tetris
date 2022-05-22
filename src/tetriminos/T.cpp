#include "T.h"

T::T()
:T(1, 1) {}

T::T(int x)
    :T(x, 1){}

T::T(int x, int y)
:Tetromino(x, y) //initializes orientation
{
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
    int x  = GetX();
    int y = GetY();
    switch (orientation) {
    case 0: {
                break;
            }
    case 1: {
                if (staticBoard[x + 2 + dx][y + 1 + dy] != ' ')
                break;
            }
    case 2: {
                //falling collision
                for (int i = 0; i < 3; i++) {
                    if (staticBoard[x + i][y + 2] != ' ')
                        return true;
                }

                if (dx > 0 && staticBoard[x + 2 + dx][y + 1] != ' ')
                    return true;

                if (dx < 0 && staticBoard[x + 1 + dx][y] != ' ')
                    return true;
                if (dx > 0 && staticBoard[x + 1 + dx][y] != ' ')
                    return true;
                break;
            }
    case 3: {
                if (staticBoard[x][y + 2 + dy] != ' ')
                    return true;
                if (staticBoard[x + dx + 1][y + 1 + dy] != ' ')
                    return true;
                break;
            }
    }
    return false;
}
