#include "menu.h"

Menu::Menu()
:selected(false), currentlyHighlighted(2), choice(0), ARRAY_SIZE(2) {
    //choices = {
    //    "Play",
    //    "Continue (WIP)",
    //    "Exit"
    //};

    choicesArr    = new std::string*[ARRAY_SIZE];
    choicesArr[0] = new std::string("Play");
    choicesArr[1] = new std::string("Exit");

    getmaxyx(stdscr, ymax, xmax);
    menuWinPtr = newwin(6, xmax-12, 8, 5);
    box(menuWinPtr, 0, 0);
    refresh();
    wrefresh(menuWinPtr);
    keypad(menuWinPtr, TRUE);
}

Menu::~Menu() {
    keypad(menuWinPtr, FALSE);
    delwin(menuWinPtr);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        delete choicesArr[i];
        choicesArr[i] = nullptr;
    }
    delete[] choicesArr;
}

void Menu::DrawMenuBox() {
    wattron(menuWinPtr, A_BOLD);
    mvwprintw(menuWinPtr, 1, 1, "W/S -> Navigation\t\tSpace -> Select");
    wattroff(menuWinPtr, A_BOLD);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i == currentlyHighlighted) {
            wattron(menuWinPtr, A_REVERSE);
        }
        mvwprintw(menuWinPtr, i+2, 1, choicesArr[i]->c_str());
        wattroff(menuWinPtr, A_REVERSE);
    }
    refresh();
    wrefresh(menuWinPtr);
}

int Menu::Run() {
    //draw the state of the menu
    currentlyHighlighted = 0;
    DrawMenuBox();
    while (!selected) {
        mvwprintw(stdscr, 0, 0, "Currently highlighted : %d", currentlyHighlighted);
        choice = getch();
        try {
            switch (choice) {
            case 'w':
            case KEY_UP:
                move(7, 0);
                clrtoeol();
                currentlyHighlighted--;
                if (currentlyHighlighted < 0) {
                    currentlyHighlighted = 0;
                    throw std::string("Cannot go outside the bound of the menu elements (-1 is invalid menu item)");
                }
                break;
            case 's':
            case KEY_DOWN:
                move(7, 0);
                clrtoeol();
                currentlyHighlighted++;
                if (currentlyHighlighted == ARRAY_SIZE) {
                    currentlyHighlighted = ARRAY_SIZE - 1;
                    throw std::string("Cannot go outside the bound of the menu elements (") + 
                        std::to_string(ARRAY_SIZE) + std::string(" is invalid menu item)");
                }
                break;
            case ' ':
                mvwprintw(stdscr, 0, 3, "Selected item");
                selected = true;
                break;
            }
        } catch(std::string& e) {
            mvwprintw(stdscr, 7, 10, e.c_str());
        }
        

        //draw the state of the menu
        DrawMenuBox();
        refresh();
        wrefresh(menuWinPtr);
    }
    return currentlyHighlighted;
}
