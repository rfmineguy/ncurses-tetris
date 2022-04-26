#pragma once
#define BOARD_WIDTH 12
#define BOARD_HEIGHT 22
#include <ncurses.h>

class Board {
    public:
        Board();
        ~Board();
        int GetCell(int x, int y);
        
        void Display();

    private:
        WINDOW* window;
        int cells[BOARD_WIDTH][BOARD_HEIGHT];
};
