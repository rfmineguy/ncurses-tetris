#include "L.h"

L::L()
:L(0, 0) {}

L::L(int x, int y)
:Tetrimino(x, y){
    pieceShapeArr = {
    '#', ' ', ' ', ' ',
    '#', ' ', ' ', ' ',
    '#', ' ', ' ', ' ',
    '#', '#', ' ', ' '
    };
}

L::~L() {}

void L::TurnPiece(int direction) {

}
