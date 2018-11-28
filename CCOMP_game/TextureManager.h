#pragma once
#include "Game.h"
#include <vector>

class TextureManager{
  
public:
    static SDL_Texture* loadTexture(const char*);
    static void Draw(SDL_Texture* tex , SDL_Rect dest);
    static std::vector<SDL_Texture*> loadVec(const char*, int);
    
    //Facade
    
};


