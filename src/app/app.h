#pragma once

#include <SDL.h>
#include <graphics/sprite/sprite.h>

typedef struct {
	SDL_Window* _window;
	SDL_Renderer* _renderer;
} App;

App createApp(int width, int height, const char* title);

inline void cleanUpApp(App* target) { SDL_DestroyWindow(target->_window); }

void renderSprite(App* target, Sprite* sprite);
inline void display(App* target) { SDL_RenderPresent(target->_renderer); }
inline void clearScreen(App* target) { SDL_RenderClear(target->_renderer); };
