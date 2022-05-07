#include "I.h"

I::I() {

}

I::I(int x, int y)
:Tetrimino(x, y) {
    pieceShapeArr = {
    '#', ' ', ' ', ' ',
    '#', ' ', ' ', ' ',
    '#', ' ', ' ', ' ',
    '#', ' ', ' ', ' ' 
    };

}
I::~I() {}

//I should rotate between two states
void I::TurnPiece(int direction) {
    
}
