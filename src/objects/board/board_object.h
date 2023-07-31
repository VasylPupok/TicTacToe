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

//void createBoardObject(SDL_Texture* emptyCell);

void getGridCoordinates(BoardObject* target, int x, int y, int* row, int* col);

void renderBoard(App* target, BoardObject* board);
