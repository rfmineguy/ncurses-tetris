#include "tetrimino.h"

Tetrimino::Tetrimino() 
:Tetrimino(0, 0) {}

Tetrimino::Tetrimino(int _pieceX, int _pieceY) 
:pieceX(_pieceX), pieceY(_pieceY), pieceWidth(4), pieceHeight(4) {}

Tetrimino::~Tetrimino() {

}

char Tetrimino::GetChar(int x, int y) const {
    return GetChar(x * 4 + y);
}

char Tetrimino::GetChar(int index) const {
    return pieceShapeArr[index];
}
