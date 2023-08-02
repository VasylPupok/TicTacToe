#include <SDL.h>
#include <SDL_image.h>

#include <graphics/texture/texture.h>
#include <app/app.h>
#include <objects/board/board_object.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

int main(int argc, char** argv) {
	SDL_assert(!SDL_Init(SDL_INIT_VIDEO));
	SDL_assert(IMG_Init(IMG_INIT_PNG));

	App* app = App_new(WINDOW_WIDTH, WINDOW_HEIGHT, "TicTacToe");
	SDL_Texture* boardTexture = loadTexture(app, "res/textures/board.jpg");
	SDL_Texture* crossTexture = loadTexture(app, "res/textures/cross.jpg");
	SDL_Texture* naughtTexture = loadTexture(app, "res/textures/naught.jpg");

	SDL_Rect spriteFrame = { 10, 10, WINDOW_WIDTH - 20, WINDOW_HEIGHT - 20};

	Sprite* boardSprite = Sprite_new(&spriteFrame, boardTexture);
	Board* board_model = Board_new();
	BoardObject board = {boardSprite, crossTexture, naughtTexture, board_model};

	short gameIsRunning = 1;
	SDL_Event event;

	int x;
	int y;
	int row;
	int col;

	while (gameIsRunning) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				gameIsRunning = 0;
			case SDL_MOUSEBUTTONUP:
				SDL_GetMouseState(&x, &y);
				BoardObject_getGridCoordinates(&board, x, y, &row, &col);
				Board_move(row, col, board._model);
			default:
				break;
			}
		}

		App_clearScreen(app);
		BoardObject_render(app, &board);
		App_display(app);

		if (Board_gameIsEnded(board._model)) {
			switch (Board_findWinner(board._model)) {
			case BOARD_FIRST_PLAYER:
				SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Game end", "First player win", app->_window);
				break;
			case BOARD_SECOND_PLAYER:
				SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Game end", "Second player win", app->_window);
				break;
			case BOARD_NONE:
				SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Game end", "Draw", app->_window);
				break;
			default:
				SDL_ShowSimpleMessageBox(
					SDL_MESSAGEBOX_ERROR, 
					"Something went wrong", 
					"It must be a bug. As a developer of this game I sincerely apologize for that", 
					app->_window
				);
				break;
			}

			gameIsRunning = 0;
		}
	}
	
	SDL_DestroyTexture(boardTexture);
	SDL_DestroyTexture(crossTexture);
	SDL_DestroyTexture(naughtTexture);

	Sprite_delete(boardSprite);
	Board_delete(board_model);
	App_delete(app);

	return 0;
}
