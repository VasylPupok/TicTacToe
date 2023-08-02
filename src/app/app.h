#pragma once

#include <SDL.h>
#include <graphics/sprite/sprite.h>

typedef struct {
	SDL_Window* _window;
	SDL_Renderer* _renderer;
} App;

App* App_new(int width, int height, const char* title);

inline void App_delete(App* target) {
	SDL_DestroyWindow(target->_window);
	SDL_DestroyRenderer(target->_renderer);
	free(target);
}

void App_renderSprite(App* target, Sprite* sprite);
inline void App_display(App* target) { SDL_RenderPresent(target->_renderer); }
inline void App_clearScreen(App* target) { SDL_RenderClear(target->_renderer); };
