#pragma once

#include <stdbool.h>
#include <SDL_image.h>

typedef struct {
	SDL_Rect _spriteFrame;
	SDL_Rect _textureFrame;
	SDL_Texture* _texture;
} Sprite;

Sprite createSprite(const SDL_Rect* spriteFrame, SDL_Texture* tex);

bool containsPoint(const Sprite* sprite, int x, int y);
