#include "Game.h"
#include "Menu.h"
#undef main

Game *game = nullptr;
Menu *menu = nullptr;

int main(){
    
    TTF_Init();
    const int FPS = 80;
    const int frameDelay = 1000/FPS;
    Uint32 frameStart;
    int frameTime;
    
    game = new Game();
    menu = new Menu();
    
    menu->init("Menu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1400, 800, false);
    menu->setStart();
    
    while (menu->running()) {
        
        frameStart = SDL_GetTicks();
        menu->events();
        menu->verify();
        menu->render();
        
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }
    menu->clearing();
    menu->clean();
    if(menu->exit) return 0;
    
    game->init("TheFinalBattle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1400, 800, false);
    game->setStart();
    while (game->running()) {
     
         frameStart = SDL_GetTicks();
        
         game->events();
         game->update();
         game->verify();
         game->render();
        
         frameTime = SDL_GetTicks() - frameStart;
         if (frameDelay > frameTime) {
         SDL_Delay(frameDelay - frameTime);
         }
     }
    game->clean();
    return 0;
}
