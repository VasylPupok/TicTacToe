#include "board.h"

#include <string.h>

void initBoard(Board* board) {
    memset(board, 0, sizeof(Board));
}

void move(int row, int col, Board* board) {
    if (board->_turn == FIRST_PLAYER_TURN) {
        board->_grid[row][col] = 1;
    } else if (board->_turn = SECOND_PLAYER_TURN) {
        board->_grid[row][col] = -1;
    }
    // intentionally do nothing if board has wrong value of _turn
}

int findWinner(Board* board) {
    char** grid = board->_grid;


    // checking diagonals
    int diagonals[2] = { 
        grid[0][0] + grid[1][1] + grid[2][2],
        grid[2][0] + grid[1][1] + grid[0][2]
    };
    if (diagonals[0] == 2 || diagonals[1] == 2) {
        return 1;
    } else if (diagonals[0] == -2 || diagonals[1] == -2) {
        return -1;
    }

    // checking rows and cols

    int rowSums[3] = { 0,0,0 };
    int colSums[3] = { 0,0,0 };

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            rowSums[row] += grid[row][col];
            colSums[col] += grid[row][col];
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (rowSums[i] == 2 || colSums[i] == 2) {
            return 1;
        } else if (rowSums[i] == -2 || colSums[i] == -2) {
            return -1;
        }
    }

    return 0;
}
