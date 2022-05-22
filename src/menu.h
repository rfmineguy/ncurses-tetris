#pragma once
#include <ncurses.h>
#include <curses.h>
#include <array>
#include <string>
#include <cstring>

class Menu {
    public:
        Menu();
        ~Menu();

        /* DrawMenuBox(void): void
         *  Description : displays the graphical aspect of the menu
         *  Params: N/A
         *  Return: N/A
         */
        void DrawMenuBox();
        
        /* Run(void):int
         *  Description : starts the loop that handles the menu selection logic
         *  Params: N/A
         *  Return: returns the item that was selected
         */
        int Run();

    private:
        WINDOW* menuWinPtr;
        int xmax, ymax;
        int currentlyHighlighted;
        char choice;
        bool selected;

        const int ARRAY_SIZE;
        std::string** choicesArr;
};
