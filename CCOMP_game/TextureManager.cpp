#include "TextureManager.h"
#include <iostream>

SDL_Texture* TextureManager::loadTexture(const char *filename){
    
    SDL_Texture* playerText;
    playerText = IMG_LoadTexture(Game::renderer, filename);
    if(playerText==NULL)
        std::cout<<"Error!!!! imagen"<<std::endl;
    else
        std::cout<<"Imagen cargada!"<<std::endl;
    return playerText;
}

void TextureManager::Draw(SDL_Texture *tex, SDL_Rect dest){
    SDL_RenderCopy(Game::renderer, tex, NULL, &dest);
}

