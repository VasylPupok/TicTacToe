#include "texture.h"
#include <util/debug/sdl_debug.h>

SDL_Texture* loadTexture(App* target, const char* path) {
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(target->_renderer, path);

	// :TODO: add path to resulting string
	// TODO add variadic concat function/macro
	SDL_ASSERT(texture, "texture was not loaded");

	return texture;
}
