#include "app.h"

App* App_new(int width, int height, const char* title) {
	App* app = malloc(sizeof(App));
	SDL_assert_paranoid(app);

	app->_window = NULL;
	app->_renderer = NULL;

	SDL_CreateWindowAndRenderer(
		width, height,
		SDL_WINDOW_SHOWN,
		&app->_window,
		&app->_renderer
	);

	SDL_assert(app->_window);
	SDL_assert(app->_renderer);

	SDL_SetWindowTitle(app->_window, title);

	return app;
}

void App_renderSprite(App* target, Sprite* sprite) {
	int err = SDL_RenderCopy(
		target->_renderer,
		sprite->_texture,
		&sprite->_textureFrame,
		&sprite->_spriteFrame
	);
	SDL_assert(!err);
}
