#include "texture.h"

SDL_Texture* loadTexture(App* target, const char* path) {
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(target->_renderer, path);
	SDL_assert(texture);

	return texture;
}
