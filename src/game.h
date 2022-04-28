#pragma once
#include "tetrimino.h"
#include <vector>
#include <ncurses.h>
#include <iostream>

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
    
    private:
        bool running;

        WINDOW* tetrisWindow;
        WINDOW* nextPieceWindow;

        std::vector<Tetrimino> tetriminos;
        Tetrimino* currentTetrimino;
        int maxx, maxy;

        int xpos, ypos;
        int width, height;

        //testMovement
        int xpos1, ypos1;
};
