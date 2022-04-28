//https://en.wikipedia.org/wiki/Tetromino

#pragma once
#pragma once
#include <array>
class Tetrimino {
    public:
        Tetrimino();
        Tetrimino(int _pieceX, int _pieceY);
        virtual ~Tetrimino();

        /* TurnPiece(int) Pure Virtual
         *   Description : turns this piece (90 * direction) degrees
         *   Param 'direction' : the direction in which to turn the piece (-1 means ccw, 1 means cw)
         *   Return : N/A
         */
        virtual void TurnPiece(int direction) = 0;

        /* GetChar(int, int)
         *   Description : converts (x, y) to single dimensional index
         *   Param 'x' : the xcoord of the "4x4" array to query
         *   Param 'y' : the ycoord of the "4x4" array to query
         *   Return : the char at the give (x, y) in 'pieceShapeArray'
         */
        char GetChar(int x, int y) const;

        /* GetChar(int)
         *   Param 'index' : the index to querry for a char
         *   Return : the char at the given index in 'pieceShapeArr'
         */
        char GetChar(int index) const;

    protected:
        //this (x,y) represents the top-left corner of the 4x4 pieceShape in the main board
        int pieceX, pieceY;
        int pieceWidth, pieceHeight;

        //get char at x,y with (x * 4 + y)
        std::array<char, 16> pieceShapeArr;
};
