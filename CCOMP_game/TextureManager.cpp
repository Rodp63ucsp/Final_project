#include "TextureManager.h"
#include <iostream>
#include <fstream>
#include <string.h>

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

std::vector<SDL_Texture*> TextureManager::loadVec(const char *filename, int t){
    std::ifstream inputFile;
    inputFile.open(filename);
    std::vector<SDL_Texture*> temp;
    for (int i = 0; i < t; i++) {
        std::string file;
        inputFile>>file;
        char imgname[file.size()+1];
        strcpy(imgname, file.c_str());
        SDL_Texture* temptexture = loadTexture(imgname);
        temp.push_back(temptexture);
    }
    inputFile.close();
    return temp;
}
