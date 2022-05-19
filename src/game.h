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
      
        /* DrawDebugWindow()
         *   Description : some logic to draw extra info that's nice to see
         *   Params : N/A
         *   Return : N/A
         */
        void DrawDebugWindow();

        /* CheckRowComplete() TODO
         *   Description : checks if any of the rows in the board are completely full
         *     if they are then clear that row and shift all rows above it down by 1
         *   Params : N/A
         *   Return : N/A
         */
        void CheckRowComplete();

        void DrawStaticBuffer();
        void DrawDynamicBuffer();

        void SpawnNewTetrimino();

        void BakeToStatic();
        void ClearDynBuff();
    
    private:
        bool running;
        int timer;
        const int FALL_SPEED;
        float fallSpeedMultiplier; //number less than 1 to increase the fall interval

        WINDOW* tetrisWindow;
        WINDOW* nextPieceWindow;

        char staticBoard[WIDTH_IN_PIECES][HEIGHT_IN_PIECES];
        char dynamicBoard[WIDTH_IN_PIECES][HEIGHT_IN_PIECES];

        Tetromino* currentTetrimino;
        Tetromino* nextTetrimino;
        int maxx, maxy;

        int xpos, ypos;
        int width, height;
};
