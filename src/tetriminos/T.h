#pragma once
#include "tetrimino.h"

class T : public Tetromino {
    public:
        T();
        T(int x);
        T(int x, int y);
        virtual ~T();
        void TurnPiece(int direction) override;
        bool WillTouchStaticPiece(int dx, int dy, char staticBoard[WIDTH_IN_PIECES][HEIGHT_IN_PIECES]) override;
};
