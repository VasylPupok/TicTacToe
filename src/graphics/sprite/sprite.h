#pragma once
#include <SDL_image.h>

typedef struct {
	SDL_Rect _spriteFrame;
	SDL_Texture* _texture;
} Sprite;

Sprite createSprite(SDL_Rect* spriteFrame, SDL_Texture* tex);
