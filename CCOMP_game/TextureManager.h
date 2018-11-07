#pragma once

#include "Game.h"

class TextureManager{
  
public:
    static SDL_Texture* loadTexture(const char*);
    static void Draw(SDL_Texture* tex , SDL_Rect dest);
};


