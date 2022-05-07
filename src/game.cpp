#include "game.h"
#include "tetriminos/I.h"
#include "tetriminos/L.h"
#include <unistd.h>
#include <iostream>


Game::Game() 
:width(WIDTH_IN_PIECES*2), height(HEIGHT_IN_PIECES*2), running(true), xpos1(1), ypos1(1), timer(0) {
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

    //tetriminos.push_back(new L(1, 1));

    for (int i = 0; i < WIDTH_IN_PIECES; i++) {
        for (int j = 0; j < HEIGHT_IN_PIECES; j++) {
            staticBoard[i][j] = ' ';
            dynamicBoard[i][j] = ' ';
        }
    }

    currentTetrimino = new L(0, 5);
}

Game::~Game() {
    delwin(tetrisWindow);
    tetrisWindow = nullptr;
    delwin(nextPieceWindow);
    nextPieceWindow = nullptr;

    delete currentTetrimino;
    currentTetrimino = nullptr;
}

void Game::Run() {
    while (running) {
        HandleInput();
        Display();
    }
    clear();
}

void Game::HandleInput() {
    if (nodelay(stdscr, 1) != ERR) {            //if a key was pressed
        int c = getch();                       //get the key the user pressed
        if (c == int('q')) {
            running = false;
        }
        else if (c == 'a') {
            currentTetrimino->DeltaPos(-1, 0);
        }
        else if (c == 'd') {
            currentTetrimino->DeltaPos(1, 0);
        }
        else if (c == 'r') {
            currentTetrimino->TurnPiece(1);
            //rotate
        }
    }
    if (timer % 20 == 0) {
        timer = 0;
        //currentTetrimino->DeltaPos(0, 1);
    }
    timer+=1;
    usleep(1000000/60.f);       //sleep 1/60 second
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

    ClearBuffers();
    currentTetrimino->Draw(dynamicBoard);

    for (int i = 1; i < WIDTH_IN_PIECES - 1; i++) {
        for (int j = 1; j < HEIGHT_IN_PIECES - 1; j++) {
            mvwprintw(tetrisWindow, j * 2    , i * 2    , "%c", dynamicBoard[i][j]);
            mvwprintw(tetrisWindow, j * 2 + 1, i * 2    , "%c", dynamicBoard[i][j]);
            mvwprintw(tetrisWindow, j * 2    , i * 2 + 1, "%c", dynamicBoard[i][j]);
            mvwprintw(tetrisWindow, j * 2 + 1, i * 2 + 1, "%c", dynamicBoard[i][j]);
        }
    }

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

void Game::ClearBuffers() {
    for (int i = 0; i < WIDTH_IN_PIECES; i++) {
        for (int j = 0; j < HEIGHT_IN_PIECES; j++) {
            dynamicBoard[i][j] = ' ';
        }
    }
}
