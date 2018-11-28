#pragma once
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include <vector>

class GameObject{
    
public:
    int ID;
    GameObject();
    GameObject(int, int, int, int, std::vector<SDL_Texture*>, int);
    void Update(int,float);
    void Render(int);
    void Render(int, std::vector<SDL_Texture*> &ss);
    void Verify(std::vector<int> &v, SDL_Rect, int, int, int, int);
    SDL_Rect getdest();
    int gettick();
    std::vector<int> colisions;
    
protected:
    float extratick = 0;
    std::vector<SDL_Texture* > sprites;
    SDL_Rect destRect;
};

