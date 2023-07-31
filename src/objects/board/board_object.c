#include "board_object.h"

void getGridCoordinates(BoardObject* target, int x, int y, int* row, int* col) {
	if (!containsPoint(target->_boardSprite, x, y)) {
		*row = -1;
		*col = -1;
		return;
	}

	int board_x = target->_boardSprite->_spriteFrame.x;
	int board_y = target->_boardSprite->_spriteFrame.y;
	int board_w = target->_boardSprite->_spriteFrame.w;
	int board_h = target->_boardSprite->_spriteFrame.h;

	*col = (int)((x - board_x) * 3.0f / board_w);
	*row = (int)((y - board_x) * 3.0f / board_h);
}

// rendering board

void renderSymbol(App* target, BoardObject* board, int row, int col) {
	//if (row < 0 || row > 2 || col < 0 || col > 2) {
	//	return;
	//}

	
	if (board->_model->_grid[row][col] == 0) { return; } // OK

	//char** grid = board->_model->_grid;
	//if (grid[row][col] == 0) { return; } // NOT OK

	// TODO figure out how to calculate this values only once
	int cell_width = board->_boardSprite->_spriteFrame.w / 3;
	int cell_height = board->_boardSprite->_spriteFrame.h / 3;

	SDL_Rect symbolRect = {
		cell_width * col, cell_height * row,
		cell_width, cell_height
	};
	SDL_Texture* symbolTex = 
		board->_model->_grid[row][col] == 1 ? 
		board->_crossTexture : 
		board->_naughtTexture;
	
	Sprite symbolSprite = createSprite(&symbolRect, symbolTex);
	renderSprite(target, &symbolSprite);

}

void renderBoard(App* target, BoardObject* board) {
	renderSprite(target, board->_boardSprite);
	for (int row = 0; row < 3; ++row) {
		for (int col = 0; col < 3; ++col) {
			renderSymbol(target, board, row, col);
		}
	}
}


