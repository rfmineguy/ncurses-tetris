//https://en.wikipedia.org/wiki/Tetromino

#pragma once
#include <array>
#include "../constants.h"

class Tetromino {
    public:
        Tetromino();
        Tetromino(int _pieceX);
        Tetromino(int _pieceX, int _pieceY);
        Tetromino(const Tetromino& t);
        virtual ~Tetromino();

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
         *   Description : N/A
         *   Param 'index' : the index to querry for a char
         *   Return : the char at the given index in 'pieceShapeArr'
         */
        char GetChar(int index) const;
     
        /* DeltaPos(int, int, char[][])
         *   Description : handles moving this piece
         *   TODO : should handle collision with pieces in the static board as well
         *   Param 'dx': the deltax to move
         *   Param 'dy': the deltay to move
         *   Param 'staticBoard': the array managing non moving objects
         *   Return : whether the piece is at the bottom of the screen
         *              or touching another piece in the board
         */
        bool DeltaPos(int dx, int dy, char staticBoard[WIDTH_IN_PIECES][HEIGHT_IN_PIECES]);

        /* WillTouchingBoundary(int, int, char[][])
         *   Description : checks to see if this tetrimino is touching a wall or the bottom after moving
         *   Param 'dx': the x direction of the movement
         *   Param 'dy': the y direction of the movement
         *   Param 'staticBoard': the array managing non moving objects
         *   Return : whether the piece has touched a boundary
         */
        bool WillTouchBoundary(int dx, int dy);

        virtual bool WillTouchStaticPiece(int dx, int dy, char staticBoard[WIDTH_IN_PIECES][HEIGHT_IN_PIECES]) = 0;

        // Getters
        int GetX() const;
        int& GetX();
        
        // Setters
        int GetY() const;
        int& GetY();
        static void SetTotalTetrominosSpawned(int);

        // WIDTH_IN_PIECES comes from constants.h
        // board should be the dynamicBoard from game.h
        void Draw(char board[WIDTH_IN_PIECES][HEIGHT_IN_PIECES]);

        friend void PrintPieceShapeArr(Tetromino* t);

    public:
        static int totalTetrominosSpawned;

    protected:
        //this (x,y) represents the top-left corner of the 4x4 pieceShape in the main board
        int pieceX, pieceY;
        int pieceWidth, pieceHeight;
        int rotation;                   //0, 1, 2, 3

        //get char at x,y with (x * 4 + y)
        std::array<char, 16> pieceShapeArr;
};
