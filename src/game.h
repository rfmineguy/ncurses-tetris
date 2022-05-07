#pragma once
#include "tetriminos/tetrimino.h"
#include <vector>
#include <ncurses.h>
#include <iostream>
#include "constants.h"

class Game {
    public:
        Game();
        ~Game();
        void Run();

        void Display();
    
    private:
        void HandleInput();
        void DrawMainTetrisWindow();
        void DrawNextPieceWindow();
        void DrawDebugInfo();

        void SaveDynamicBoardToStatic();
        void ClearBuffers();
    
    private:
        bool running;
        int timer;

        WINDOW* tetrisWindow;
        WINDOW* nextPieceWindow;

        char staticBoard[WIDTH_IN_PIECES][HEIGHT_IN_PIECES];
        char dynamicBoard[WIDTH_IN_PIECES][HEIGHT_IN_PIECES];

        Tetrimino* currentTetrimino;
        Tetrimino* nextTetrimino;
        int maxx, maxy;

        int xpos, ypos;
        int width, height;

        //testMovement
        int xpos1, ypos1;
};
