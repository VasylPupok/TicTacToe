#include "sprite.h"
#include <util/debug/sdl_debug.h>

Sprite createSprite(const SDL_Rect* spriteFrame, SDL_Texture* tex) {
    int width;
    int height;
    int querry_err = SDL_QueryTexture(tex, NULL, NULL, &width, &height);
    SDL_ASSERT(!querry_err, "error querying texture for sprite");
    Sprite sprite = {*spriteFrame, {0,0, width, height}, tex};
    return sprite;
}

bool containsPoint(const Sprite* sprite, int x, int y) {
    return 
        sprite->_spriteFrame.x < x && x < sprite->_spriteFrame.x + sprite->_spriteFrame.w &&
        sprite->_spriteFrame.y < y && y < sprite->_spriteFrame.y + sprite->_spriteFrame.h;
}
