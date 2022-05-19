#include <iostream>
#include <ncurses.h>
#include <curses.h>
#include "game.h"
#include "menu.h"

//https://www.linuxjournal.com/content/getting-started-ncurses
//https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/
//

void setupCurses();

int main() {
    initscr();
    setupCurses();
    Menu* menu = new Menu();
    int selected = menu->Run();
    delete menu;
    std::cout << "Selected " << selected << '\n';
    clear();
    Game* game = new Game();
    if (selected == 0) {
        game->Run();
    }
    delete game;
    endwin();

    return EXIT_SUCCESS;
}

void setupCurses() {
    //raw();
    keypad(stdscr, TRUE);       //enables arrow keys, function keys, etc.
    clear();

    if (!has_colors()) {
        printw("Terminal doesn't support color");
        getch();
        std::cout << "Colors not supported" << std::endl;
    }
    else {
        printw("Terminal supports color");
        start_color();
    }
}
