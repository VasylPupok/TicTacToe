#include "board.h"

#include <string.h>

Board createBoard() {
    Board board;
    memset(&board, 0, sizeof(Board));
    board._turn = BOARD_FIRST_PLAYER;
    board._movesMade = 0;
    return board;
}

void move(int row, int col, Board* board) {
    if (row < 0 || row > 2 || col < 0 || col > 2) return;

    if (board->_turn == BOARD_FIRST_PLAYER) {
        board->_grid[row][col] = 1;
        board->_turn = BOARD_SECOND_PLAYER;
        ++board->_movesMade;
    } else if (board->_turn = BOARD_SECOND_PLAYER) {
        board->_grid[row][col] = -1;
        board->_turn = BOARD_FIRST_PLAYER;
        ++board->_movesMade;
    }
    // intentionally do nothing if board has wrong value of _turn
}

int findWinner(const Board* board) {
    // checking diagonals
    int diagonals[2] = { 
        board->_grid[0][0] + board->_grid[1][1] + board->_grid[2][2],
        board->_grid[2][0] + board->_grid[1][1] + board->_grid[0][2]
    };
    if (diagonals[0] == 3 || diagonals[1] == 3) {
        return BOARD_FIRST_PLAYER;
    } else if (diagonals[0] == -3 || diagonals[1] == -3) {
        return BOARD_SECOND_PLAYER;
    }

    // checking rows and cols

    int rowSums[3] = { 0,0,0 };
    int colSums[3] = { 0,0,0 };

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            rowSums[row] += board->_grid[row][col];
            colSums[col] += board->_grid[row][col];
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (rowSums[i] == 3 || colSums[i] == 3) {
            return BOARD_FIRST_PLAYER;
        } else if (rowSums[i] == -3 || colSums[i] == -3) {
            return BOARD_SECOND_PLAYER;
        }
    }

    return BOARD_NONE;
}

int gameIsEnded(const Board* board) {
    return board->_movesMade == 9 || findWinner(board) != BOARD_NONE;
}
