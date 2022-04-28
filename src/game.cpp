#include "game.h"
#include <unistd.h>
#include <iostream>


Game::Game() 
:width(24*2), height(22*2), running(true), xpos1(1), ypos1(1) {
    getmaxyx(stdscr,maxy,maxx);

    std::cout << maxx << " " << maxy << std::endl;
    xpos = (maxx / 2) - (width / 2);
    ypos = (maxy / 2) - (height / 2);
    tetrisWindow = newwin(height, width, ypos, xpos);
    nextPieceWindow = newwin(4*2, 10*2, ypos, xpos + width);
    refresh();
    keypad(tetrisWindow, TRUE);

    //colors
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
}

Game::~Game() {
    delwin(tetrisWindow);
    tetrisWindow = nullptr;
    delwin(nextPieceWindow);
    nextPieceWindow = nullptr;
}

void Game::Run() {
    while (running) {
        Display();
        if (nodelay(stdscr, 1) != ERR) {            //if a key was pressed
            int c = getch();                       //get the key the user pressed
            if (c == int('q')) {
                mvwprintw(stdscr, 4, 11, "quit");
                running = false;
            }
            else if (c == 'a') {
                xpos1--;
            }
            else if (c == 'd') {
                xpos1++;
            }
        }
        usleep(1000000/60.f);       //sleep 1/60 second
    }
}

void Game::HandleInput() {

}

void Game::Display() {
    //Main Tetris Window
    DrawMainTetrisWindow();
    DrawNextPieceWindow();
    refresh();
}

void Game::DrawMainTetrisWindow() {
    wbkgd(tetrisWindow, COLOR_PAIR(1));
    attron(COLOR_PAIR(1));
    box(tetrisWindow, 0, 0);
    
    mvwprintw(tetrisWindow, 0, (width/2)-(5/2), "TETRIS");

    for (int i = 1; i < width - 1; i++) {
        for (int j = 1; j < height - 1; j++) {
            mvwprintw(tetrisWindow, j, i, "%s", " ");
        }
    }
    mvwprintw(tetrisWindow, ypos1, xpos1, "%s", "$");
    wrefresh(tetrisWindow);
    attroff(COLOR_PAIR(1));
}

void Game::DrawNextPieceWindow() {
    wbkgd(nextPieceWindow, COLOR_PAIR(1));

    attron(COLOR_PAIR(1));
    box(nextPieceWindow, 0, 0);
    mvwprintw(nextPieceWindow, 0, ((4*2)/2)+(4/2), "NEXT");

    wrefresh(nextPieceWindow);
    attroff(COLOR_PAIR(1));
}
