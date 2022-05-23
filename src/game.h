#pragma once
#include "tetriminos/tetrimino.h"
#include <vector>
#include <ncurses.h>
#include <iostream>
#include "constants.h"  //file that holds some general game constants needed in multiple files

class Game {
    public:
        Game();
        ~Game();
        void Run();

        void Display();
    
    private:
        /* HandleInput(void)
         *   Description : deals with checking which key the user may be pressing
         *      * utilizes nodelay() and getch()
         *   Params : N/A
         *   Return : N/A
         */
        void HandleInput();

        /* DrawMainTetrisWindow(void)
         *   Description : some logic to handle drawing the dynamic and static buffers to the screen
         *   Params : N/A
         *   Return : N/A
         */
        void DrawMainTetrisWindow();

        /* DrawNextPieceWindow()
         *   Description : some logic to handle drawing the next piece
         *   Params : N/A
         *   Return : N/A
         */
        void DrawNextPieceWindow();
      
        /* DrawControlsWindow()
         *   Description : some logic to draw extra info that's nice to see
         *   Params : N/A
         *   Return : N/A
         */
        void DrawControlsWindow();

        /* DrawPieceCountingWindow()
         *   Description : some logic to draw how many of each piece has been spawned so far
         *              TODO sort the result based on how many have been spawned
         *   Params : N/A
         *   Return : N/A
         */
        void DrawPieceCountingWindow();

        /* CheckRowComplete() TODO
         *   Description : checks if any of the rows in the board are completely full
         *     if they are then clear that row and shift all rows above it down by 1
         *   Params : N/A
         *   Return : N/A
         */
        void CheckRowComplete();

        /* IsRowFull(int)
         *   Description : checks to see if all of the elements in a row have something in them
         *   Param 'row' : which row are we checking?
         *   Return : whether the row is full or not (true if yes, false if no)
         */
        bool IsRowFull(int row);

        /* Draw____Buffer() 
         *   Description : draws the appropriate buffer contents to the appropriate ncurses window
         *   Params : N/A
         *   Return : N/A
         */
        void DrawStaticBuffer();
        void DrawDynamicBuffer();

        /* SpawnNewTetrimino()
         *   Description : 
         *   Params : N/A
         *   Return : N/A
         */
        void SpawnNewTetrimino();

        /* BakeToStatic()
         *   Description : copies the dynamic buffer to the static buffer while ignoring blanks
         *   Params : N/A
         *   Return : N/A
         */
        void BakeToStatic();

        /* ClearDynBuff()
         *   Description : "zeroes" out the dynamic buffer for the next "render" pass
         *   Params : N/A
         *   Return : N/A
         */
        void ClearDynBuff();

    private:
        /* GetPieceCountIndex(const std::string&)
         *   Description : finds the element in the pieceCounting vector and returns its index
         *   Params : the piece your trying to find
         *   Return : the index of the piece, -1 if not found
         */
        int GetPieceCountIndex(const std::string& name);

    private:
        bool running;
        bool paused;
        int timer;
        const int FALL_SPEED, SPEED_INCREASE_INTERVAL;
        float fallSpeedMultiplier; //number less than 1 to increase the fall interval

        WINDOW* tetrisWindow;
        WINDOW* nextPieceWindow;
        WINDOW* controlsWindow;
        WINDOW* pieceCountingWindow;

        char staticBoard[WIDTH_IN_PIECES][HEIGHT_IN_PIECES];
        char dynamicBoard[WIDTH_IN_PIECES][HEIGHT_IN_PIECES];
        
        //0:L, 1:I, 2:T, 3:Square
        std::array<std::pair<std::string, int>, 4> spawnedPieces;   //i want my own sorting on this. (no map)
        Tetromino* currentTetrimino;
        Tetromino* nextTetrimino;
        int maxx, maxy;

        int xpos, ypos;
        int width, height;
};
