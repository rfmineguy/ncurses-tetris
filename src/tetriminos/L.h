#include "tetrimino.h"

class L : public Tetromino {
public:
    L();
    L(int x);
    L(int x, int y);
    virtual ~L();
    void TurnPiece(int direction) override;
    bool WillTouchStaticPiece(int dx, int dy, char staticBoard[WIDTH_IN_PIECES][HEIGHT_IN_PIECES]) override;
};
