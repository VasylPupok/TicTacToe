#include "mouse.h"

void onMousePressed(SDL_Event* event, void(*onMousePressed)(int mousePosX, int mousePosY, mouse_btn_t mouseButton)) {
	int x;
	int y;
	SDL_GetMouseState(&x, &y);
	onMousePressed(x, y, event->button.button);
}

void onMouseReleased(SDL_Event* event, void(*onMouseReleased)(int mousePosX, int mousePosY, mouse_btn_t mouseButton)) {
	int x;
	int y;
	SDL_GetMouseState(&x, &y);
	onMouseReleased(x, y, event->button.button);
}
