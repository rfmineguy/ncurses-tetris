#include "game.h"
#include "tetriminos/I.h"
#include "tetriminos/L.h"
#include "tetriminos/T.h"
#include "tetriminos/square.h"
#include <unistd.h>
#include <iostream>

void PrintPieceShapeArr(Tetromino* t);

Game::Game() 
:width(WIDTH_IN_PIECES*2), 
    height(HEIGHT_IN_PIECES*2), 
    running(true), 
    timer(0), 
    FALL_SPEED(30),
    SPEED_INCREASE_INTERVAL(600),   //Every 600/60 seconds = 10 seconds
    fallSpeedMultiplier(0.1f){

    getmaxyx(stdscr, maxy, maxx);

    srand(time(0));
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

    // spawn the initial tetrimino
    SpawnNewTetrimino();
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
    refresh();
}

void Game::HandleInput() {
    if (nodelay(stdscr, 1) != ERR) {            //if a key was pressed
        int c = getch();                        //get the key the user pressed
        if (c == 'q') {
            running = false;
        }
        else if (c == 'a') {
            currentTetrimino->DeltaPos(-1, 0, staticBoard);
        }
        else if (c == 'd') {
            currentTetrimino->DeltaPos(1, 0, staticBoard);
        }
        else if (c == 's') {
            currentTetrimino->DeltaPos(0, 1, staticBoard);
        }
        else if (c == 'r') {
            currentTetrimino->TurnPiece(1);     //TODO make this actually work
            //rotate
        }
        //else if (c == 'k') {
        //    fallSpeedMultiplier+=0.1;
        //}
        //else if (c == 'j') {
        //    fallSpeedMultiplier-=0.1;
        //}
    }
    if (timer % SPEED_INCREASE_INTERVAL == 0)
        fallSpeedMultiplier+=0.1;
    if (timer % (int)(FALL_SPEED * (1 - fallSpeedMultiplier)) == 0) {
        //timer = 0;
        if (currentTetrimino->DeltaPos(0, 1, staticBoard)) {
            mvwprintw(stdscr, 0, 0, "At the bottom");
            wrefresh(tetrisWindow);
            BakeToStatic();
            SpawnNewTetrimino();
            CheckRowComplete();
        }
    }
    timer+=1;
    usleep(1000000/60.f);       //sleep 1/60 second
}

void Game::Display() {
    //Main Tetris Window
    clearok(tetrisWindow, true);
    DrawMainTetrisWindow();
    DrawNextPieceWindow();
    refresh();
}

void Game::DrawMainTetrisWindow() {
    wbkgd(tetrisWindow, COLOR_PAIR(1));
    attron(COLOR_PAIR(1));
    box(tetrisWindow, 0, 0);

    mvwprintw(tetrisWindow, 0, (width/2)-(5/2), "TETRIS");

    ClearDynBuff();
    currentTetrimino->Draw(dynamicBoard);

    DrawStaticBuffer();
    DrawDynamicBuffer();
    wrefresh(tetrisWindow);
    attroff(COLOR_PAIR(1));
}

void Game::DrawNextPieceWindow() {
    wbkgd(nextPieceWindow, COLOR_PAIR(1));

    attron(COLOR_PAIR(1));
    box(nextPieceWindow, 0, 0);
    mvwprintw(nextPieceWindow, 0, ((4*2)/2)+4, "NEXT");

    wrefresh(nextPieceWindow);
    attroff(COLOR_PAIR(1));
}

void Game::CheckRowComplete() {
    /*  1. Loop over all the rows from the bottom up
     *  2. Check to see if that row is full
     *  3. If it is clear it and shift everything above it down
     *
     *  Pseudo Code :
     *  for i from 0 to height:
     *      //check the i-th row
     *      int countFullSpots
     *      for j from 0 to width:
     *          if '#': countFullSpots++
     *      if countFullSpot == width
     *          //clear and shift
     */

    //loop over rows
    for (int j = 0; j < HEIGHT_IN_PIECES; j++) {
        int countFull = 0;
        for  (int i = 0; i < WIDTH_IN_PIECES; i++) {
            //count the row
            if (staticBoard[i][j] == '#')
                countFull++;
        }
        //check the row's count
        if (countFull == WIDTH_IN_PIECES) {
            //shift the rows above row 'j' down
            for (int z = j; z < WIDTH_IN_PIECES; z++) {
                staticBoard[j][z] = staticBoard[j - 1][z];
            }
            for (int i = 0; i < WIDTH_IN_PIECES; i++) {
                staticBoard[i][HEIGHT_IN_PIECES - 1] = ' ';
            }
        }
    }
}

void Game::DrawDynamicBuffer() {
    for (int i = 1; i < WIDTH_IN_PIECES - 1; i++) {
        for (int j = 1; j < HEIGHT_IN_PIECES - 1; j++) {
            if (dynamicBoard[i][j] == ' ')
                continue;
            mvwprintw(tetrisWindow, j * 2    , i * 2    , "%c", dynamicBoard[i][j]);
            mvwprintw(tetrisWindow, j * 2 + 1, i * 2    , "%c", dynamicBoard[i][j]);
            mvwprintw(tetrisWindow, j * 2    , i * 2 + 1, "%c", dynamicBoard[i][j]);
            mvwprintw(tetrisWindow, j * 2 + 1, i * 2 + 1, "%c", dynamicBoard[i][j]);
        }
    }
}

void Game::DrawStaticBuffer() {
    for (int i = 1; i < WIDTH_IN_PIECES - 1; i++) {
        for (int j = 1; j < HEIGHT_IN_PIECES - 1; j++) {
            mvwprintw(tetrisWindow, j * 2    , i * 2    , "%c", staticBoard[i][j]);
            mvwprintw(tetrisWindow, j * 2 + 1, i * 2    , "%c", staticBoard[i][j]);
            mvwprintw(tetrisWindow, j * 2    , i * 2 + 1, "%c", staticBoard[i][j]);
            mvwprintw(tetrisWindow, j * 2 + 1, i * 2 + 1, "%c", staticBoard[i][j]);
        }
    }
}

void Game::SpawnNewTetrimino() {
    delete currentTetrimino;
    currentTetrimino = nullptr;
    int r = rand() % 20;

    if (r < 5) {
        currentTetrimino = new I(WIDTH_IN_PIECES/2);
    }
    else if (r < 10) {
        currentTetrimino = new L(WIDTH_IN_PIECES/2);
    }
    else if (r < 15) {
        currentTetrimino = new T(WIDTH_IN_PIECES/2);
    }
    else if (r < 20) {
        currentTetrimino = new Square(WIDTH_IN_PIECES/2);
    }
}

void Game::BakeToStatic() {
    for (int i = 0; i < WIDTH_IN_PIECES; i++) {
        for (int j = 0; j < HEIGHT_IN_PIECES; j++) {
            if (staticBoard[i][j] == ' ')
                staticBoard[i][j] = dynamicBoard[i][j];
        }
    }
}

void Game::ClearDynBuff() {
    for (int i = 0; i < WIDTH_IN_PIECES; i++) {
        for (int j = 0; j < HEIGHT_IN_PIECES; j++) {
            dynamicBoard[i][j] = ' ';
        }
    }
}

void PrintPieceShapeArr(Tetromino* t) {
    std::cout << "Tetromino pattern : \n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << t->pieceShapeArr[i * 4 + j] << ", ";
        }
        std::cout << std::endl;
    }
}
