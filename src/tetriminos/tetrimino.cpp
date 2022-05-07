#include "tetrimino.h"
#include "../exceptions.h"

Tetrimino::Tetrimino() 
:Tetrimino(0, 0) {}

Tetrimino::Tetrimino(int _pieceX, int _pieceY) 
:pieceX(_pieceX), pieceY(_pieceY), pieceWidth(4), pieceHeight(4) {}

Tetrimino::~Tetrimino() {

}

// pure virtual method
// void Tetrimino::TurnPiece(int direction);

char Tetrimino::GetChar(int x, int y) const {
    return GetChar(x * pieceWidth + y);
}

char Tetrimino::GetChar(int index) const {
    return pieceShapeArr[index];
}

void Tetrimino::DeltaPos(int dx, int dy) {
    if (pieceX + dx <= 0 || pieceY + dy < 0 || pieceX + 2 + dx > WIDTH_IN_PIECES - 1 || pieceY + 2 + dy > HEIGHT_IN_PIECES - 1) {

    }
    else {
        pieceX += dx;
        pieceY += dy;
    }
}

int Tetrimino::GetX() const {
    return pieceX;
}

int& Tetrimino::GetX() {
    return pieceX;
}

int& Tetrimino::GetY() {
    return pieceY;
}

void Tetrimino::Draw(char board[WIDTH_IN_PIECES][HEIGHT_IN_PIECES]) {
    const int pieceMultiplier = 0;
    for (int i = 0; i < pieceWidth; i++) {
        for (int j = 0; j < pieceHeight; j++) {
            char c = GetChar(j,i);
            if (c != ' ') {
                board[pieceX + i][pieceY + j] = c;
            }
        }
    }
}
