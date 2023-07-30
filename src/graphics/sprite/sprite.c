#include "sprite.h"

Sprite createSprite(SDL_Rect* spriteFrame, SDL_Texture* tex) {
    Sprite sprite = {*spriteFrame, tex};
    return sprite;
}
