#pragma once

#include <SDL.h>

typedef unsigned char mouse_btn_t;

void onMousePressed(SDL_Event* event, void (*onMousePressed)(int mousePosX, int mousePosY, mouse_btn_t mouseButton));

void onMouseReleased(SDL_Event* event, void (*onMouseReleased)(int mousePosX, int mousePosY, mouse_btn_t mouseButton));
