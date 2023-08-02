#pragma once

typedef enum {
	BOARD_SECOND_PLAYER = -1,
	BOARD_NONE = 0,
	BOARD_FIRST_PLAYER = 1
} BoardPlayer;

typedef struct {
	char _grid[3][3];
	char _turn;
	int _movesMade;
} Board;

Board* Board_new();
void Board_delete(Board* target);

void Board_move(int row, int col, Board* board);
BoardPlayer Board_findWinner(const Board* board);
int Board_gameIsEnded(const Board* board);
