#include <SDL.h>
#include <SDL_image.h>

#include <util/debug/sdl_debug.h>
#include <graphics/texture/texture.h>
#include <app/app.h>

int main(int argc, char** argv) {
	SDL_ASSERT(!SDL_Init(SDL_INIT_VIDEO), "video initialization failed");
	SDL_ASSERT(IMG_Init(IMG_INIT_PNG), "image initialization failed");

	App app = createApp(1280, 840, "TicTacToe");
	SDL_Texture* texture = loadTexture(&app, "res/textures/ground_grass_1.png");

	SDL_Rect spriteFrame = { 0, 0, 64, 64 };
	Sprite test = createSprite(&spriteFrame, texture);

	short gameIsRunning = 1;
	SDL_Event event;

	while (gameIsRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				gameIsRunning = 0;
			}
		}

		clearScreen(&app);
		renderSprite(&app, &test);
		display(&app);
	}

	cleanUpApp(&app);

	return 0;
}