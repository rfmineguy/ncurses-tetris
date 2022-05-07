#include "tetrimino.h"

class L : public Tetrimino {
public:
    L();
    L(int x, int y);
    virtual ~L();
    void TurnPiece(int direction) override;
};
