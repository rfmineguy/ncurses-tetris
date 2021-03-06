#include "tetrimino.h"

class I : public Tetromino {
    public:
        I();
        I(int x);
        I(int x, int y);
        virtual ~I();
        void TurnPiece(int direction) override;
        bool WillTouchStaticPiece(int dx, int dy, char staticBoard[WIDTH_IN_PIECES][HEIGHT_IN_PIECES]) override;
};
