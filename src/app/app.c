#include <util/debug/sdl_debug.h>
#include "app.h"

App createApp(int width, int height, const char* title) {
	App app = { NULL, NULL };

	app._window = SDL_CreateWindow(
		title,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		width, height,
		SDL_WINDOW_SHOWN
	);
	SDL_ASSERT(app._window, "error loading window");

	app._renderer = SDL_CreateRenderer(app._window, -1, SDL_RENDERER_ACCELERATED);
	SDL_ASSERT(app._renderer, "error loading renderer");

	return app;
}

void renderSprite(App* target, Sprite* sprite) {
	int err = SDL_RenderCopy(
		target->_renderer,
		sprite->_texture,
		&sprite->_textureFrame,
		&sprite->_spriteFrame
	);
	SDL_ASSERT(!err, "error rendering sprite");
}
