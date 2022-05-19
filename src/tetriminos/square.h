#pragma once
#include "tetrimino.h"

class Square : public Tetromino {
    public:
        Square();
        Square(int x);
        Square(int x, int y);
        virtual ~Square();

        void TurnPiece(int direction) override;
        bool WillTouchStaticPiece(int dx, int dy, char staticBoard[WIDTH_IN_PIECES][HEIGHT_IN_PIECES]) override;
};
