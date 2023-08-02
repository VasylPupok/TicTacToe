#pragma once

#include <SDL.h>
#include <app/app.h>
#include <models/board/board.h>

typedef struct {
	Sprite* _boardSprite;
	SDL_Texture* _crossTexture;
	SDL_Texture* _naughtTexture;
	Board* _model;
} BoardObject;

void BoardObject_getGridCoordinates(BoardObject* target, int x, int y, int* row, int* col);

void BoardObject_render(App* target, BoardObject* board);
