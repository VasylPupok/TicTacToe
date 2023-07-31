#pragma once

#define FIRST_PLAYER 1
#define SECOND_PLAYER -1

typedef struct {
	char _grid[3][3];
	char _turn; // 1 if first player turn, -1 if second player
} Board;

Board createBoard();

void move(int row, int col, Board* board);
int findWinner(Board* board);
