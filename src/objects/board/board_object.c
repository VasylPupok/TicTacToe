#include "board_object.h"

void BoardObject_getGridCoordinates(BoardObject* target, int x, int y, int* row, int* col) {
	if (!Sprite_containsPoint(target->_boardSprite, x, y)) {
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
	if (board->_model->_grid[row][col] == 0) { return; }

	// TODO figure out how to calculate this values only once
	int board_x = board->_boardSprite->_spriteFrame.x;
	int board_y = board->_boardSprite->_spriteFrame.y;
	int cell_width = board->_boardSprite->_spriteFrame.w / 3;
	int cell_height = board->_boardSprite->_spriteFrame.h / 3;

	SDL_Rect symbolRect = {
		board_x + cell_width * col, board_y + cell_height * row,
		cell_width, cell_height
	};
	SDL_Texture* symbolTex = 
		board->_model->_grid[row][col] == 1 ? 
		board->_crossTexture : 
		board->_naughtTexture;
	
	Sprite* symbolSprite = Sprite_new(&symbolRect, symbolTex);
	App_renderSprite(target, symbolSprite);

}

void BoardObject_render(App* target, BoardObject* board) {
	App_renderSprite(target, board->_boardSprite);
	for (int row = 0; row < 3; ++row) {
		for (int col = 0; col < 3; ++col) {
			renderSymbol(target, board, row, col);
		}
	}
}


