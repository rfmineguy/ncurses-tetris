#include "L.h"

L::L()
:L(0, 0) {}

L::L(int x)
:L(x, 0){}

L::L(int x, int y)
:Tetromino(x, y) {
    TurnPiece(0);
}

L::~L() {}

void L::TurnPiece(int direction) {
    orientation += direction;
    orientation %= 4;
    switch (orientation) {
    case 0: {
            pieceShapeArr = {
                '#', ' ', ' ', ' ',
                '#', ' ', ' ', ' ',
                '#', ' ', ' ', ' ',
                '#', '#', ' ', ' '
            };
            pieceWidth = 2;
            pieceHeight = 4;
            break;
        }
    case 1: {
            pieceShapeArr = {
                ' ', ' ', ' ', '#',
                '#', '#', '#', '#',
                ' ', ' ', ' ', ' ',
                ' ', ' ', ' ', ' ',
            };
            pieceWidth = 4;
            pieceHeight = 2;
            break;
        } 
    case 2: {
            pieceShapeArr = {
                '#', '#', ' ', ' ',
                ' ', '#', ' ', ' ',
                ' ', '#', ' ', ' ',
                ' ', '#', ' ', ' '
            };
            pieceWidth = 2;
            pieceHeight = 4;
            break;
        }
    case 3: {
            pieceShapeArr = {
                '#', '#', '#', '#',
                '#', ' ', ' ', ' ',
                ' ', ' ', ' ', ' ',
                ' ', ' ', ' ', ' '
            };
            pieceWidth = 4;
            pieceHeight = 2;
            break;
        }
    }
}

//maybe do collision based on rotation
bool L::WillTouchStaticPiece(int dx, int dy, char staticBoard[WIDTH_IN_PIECES][HEIGHT_IN_PIECES]) {
    int x = GetX();
    int y = GetY();
    switch (orientation) {
    case 0: {
                for (int j = 0; j < 2; j++) {
                    if (staticBoard[x + j + dx][y + pieceHeight + dy - 1] != ' ')
                        return true;
                }
                break;
            }
        break;
    case 1: {
                for (int i = 0; i < pieceWidth; i++) {
                    if (staticBoard[x + i + dx][y + dy] != ' ')
                        return true;
                }
                break;
            }
        break;
    case 2: {
                for (int j = 0; j < pieceHeight; j++) {
                    if (staticBoard[x + dx + 1][y + j + dy] != ' ')
                        return true;
                }
                if (staticBoard[x + dx][y + dy] != ' ')
                    return true;
            }
        break;
    case 3: {
                for (int j = 1; j < pieceWidth; j++) {
                    if (staticBoard[x + j][y + dy] != ' ')
                        return true;
                }
                if (dx < 0 && staticBoard[x + dx][y + 1] != ' ')
                    return true;
                if (dx > 0 && staticBoard[x + dx][y + 1] != ' ') {
                    return true;
                }
                if (staticBoard[x][y + 1 +1] != ' ') {
                    return true;
                }
            }
        break;
    }
    return false;
}
