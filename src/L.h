#include "tetrimino.h"

class L : public Tetrimino {
public:
    L();
    ~L();
    void TurnPiece(int direction) override;
};
