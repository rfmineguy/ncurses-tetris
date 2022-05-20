#include "tetrimino.h"
#include "curses.h"

int Tetromino::totalTetrominosSpawned = 0;

Tetromino::Tetromino() 
:Tetromino(0, 0) {}

Tetromino::Tetromino(int _pieceX)
    :Tetromino(_pieceX, 0) {}

Tetromino::Tetromino(int _pieceX, int _pieceY) 
:pos(_pieceX, _pieceY), pieceWidth(4), pieceHeight(4), orientation(0) {
    Tetromino::totalTetrominosSpawned++;
}

Tetromino::Tetromino(const Tetromino& t) 
:pos(t.pos), pieceWidth(t.pieceWidth), pieceHeight(t.pieceHeight), orientation(t.orientation) {
    for (int i = 0; i < pieceWidth * pieceHeight; i++) {
        pieceShapeArr[i] = t.pieceShapeArr[i];
    }
}

Tetromino::~Tetromino() {
    //delete pieceShapeArr;
    //pieceShapeArr = nullptr;
}

// pure virtual method
// void Tetromino::TurnPiece(int direction);

char Tetromino::GetChar(int x, int y) const {
    return GetChar(x * 4 + y);
}

char Tetromino::GetChar(int index) const {
    std::array<char, 16>::const_iterator cit = pieceShapeArr.begin();
    return *(cit + index);
}

bool Tetromino::DeltaPos(int dx, int dy, char staticBoard[WIDTH_IN_PIECES][HEIGHT_IN_PIECES]) {
    bool touchingBoundary = WillTouchBoundary(dx, dy);
    bool touchingOtherPiece = WillTouchStaticPiece(dx, dy, staticBoard); //pure virtual function implemented in child classes
    
    if (touchingBoundary || touchingOtherPiece) {
        return true;
    }
    else {
        pos += Position{dx, dy};//.SetX() += dx;
        //pieceY += dy;
        return false;
    }
}

bool Tetromino::WillTouchBoundary(int dx, int dy) {
    bool touchingLeftEdge = GetX() + dx <= 0;
    bool touchingTopEdge = GetY() + pieceHeight + dy < 0;
    bool touchingRightEdge = GetX() + pieceWidth + dx > WIDTH_IN_PIECES - 1;
    bool touchingBottomEdge = GetY() + pieceHeight + dy > HEIGHT_IN_PIECES - 1;

    bool touchingEdge = touchingLeftEdge || touchingRightEdge || touchingTopEdge || touchingBottomEdge;
    return touchingEdge;
}

int Tetromino::GetX() const {
    return pos.GetX();
}

int Tetromino::GetY() const {
    return pos.GetY();
}

void Tetromino::Draw(char board[WIDTH_IN_PIECES][HEIGHT_IN_PIECES]) {
    const int pieceMultiplier = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            char c = GetChar(j,i);
            if (c != ' ') {
                board[pos.GetX() + i][pos.GetY() + j] = c;
            }
        }
    }
}
