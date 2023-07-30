#pragma once

#define FIRST_PLAYER_TURN 0
#define SECOND_PLAYER_TURN 1

typedef struct {
	char _grid[3][3];
	char _turn; // 0 if first player turn, 1 if second player
} Board;

void initBoard(Board* board);

void move(int row, int col, Board* board);
int findWinner(Board* board);
