#include "board.h"
#include <string>

Board::Board() {
    window = newwin(BOARD_HEIGHT, BOARD_WIDTH, 0, 0);
}

Board::~Board() {

}

int Board::GetCell(int x, int y) {
    return cells[x][y];
}

void Board::Display() {
    box(window, 0, 0);
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            mvwaddstr(window, j, i, std::to_string(cells[i][j]).c_str());
        }
    }
    wrefresh(window);
}
