#pragma once

#define BOARD_FIRST_PLAYER 1
#define BOARD_SECOND_PLAYER -1
#define BOARD_NONE 0

typedef struct {
	unsigned char _grid[3][3];
	unsigned char _turn;
	unsigned char _movesMade;
} Board;

Board createBoard();

void move(int row, int col, Board* board);
int findWinner(const Board* board);
int gameIsEnded(const Board* board);
