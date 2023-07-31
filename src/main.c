#include <SDL.h>
#include <SDL_image.h>

#include <util/debug/sdl_debug.h>
#include <graphics/texture/texture.h>
#include <app/app.h>
#include <objects/board/board_object.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

int main(int argc, char** argv) {
	SDL_ASSERT(!SDL_Init(SDL_INIT_VIDEO), "video initialization failed");
	SDL_ASSERT(IMG_Init(IMG_INIT_PNG), "image initialization failed");

	App app = createApp(WINDOW_WIDTH, WINDOW_HEIGHT, "TicTacToe");
	SDL_Texture* boardTexture = loadTexture(&app, "res/textures/board.jpg");
	SDL_Texture* crossTexture = loadTexture(&app, "res/textures/cross.jpg");
	SDL_Texture* naughtTexture = loadTexture(&app, "res/textures/naught.jpg");

	SDL_Rect spriteFrame = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };

	Sprite boardSprite = createSprite(&spriteFrame, boardTexture);

	Board board_model = createBoard();

	BoardObject board = {&boardSprite, crossTexture, naughtTexture, &board_model};

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
				getGridCoordinates(&board, x, y, &row, &col);
				move(row, col, board._model);
			default:
				break;
			}
		}

		clearScreen(&app);	
		renderBoard(&app, &board);
		display(&app);

		if (gameIsEnded(board._model)) {
			// TODO add win screen
			SDL_Delay(3000);
			gameIsRunning = 0;
		}
	}

	cleanUpApp(&app);

	return 0;
}