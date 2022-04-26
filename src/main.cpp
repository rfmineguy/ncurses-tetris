#include <iostream>
#include <ncurses.h>
#include "board.h"

//https://www.linuxjournal.com/content/getting-started-ncurses

int main() {
    Board b;
    initscr();

    addstr("-----------------\n| codedrome.com |\n| ncurses Demo  |\n-----------------\n\n");
    refresh();

    //printing();

    //moving_and_sleeping();

    //colouring();

    b.Display();
    addstr("\npress any key to exit...");
    refresh();

    getch();

    endwin();

    return EXIT_SUCCESS;
}
