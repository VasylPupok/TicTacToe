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

	while (gameIsRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				gameIsRunning = 0;
			}
		}

		clearScreen(&app);	
		renderBoard(&app, &board);
		display(&app);
	}

	cleanUpApp(&app);

	return 0;
}