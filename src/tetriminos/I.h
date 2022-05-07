#include "tetrimino.h"

class I : public Tetrimino {
    public:
        I();
        I(int x, int y);
        virtual ~I();
        void TurnPiece(int direction) override;
};
