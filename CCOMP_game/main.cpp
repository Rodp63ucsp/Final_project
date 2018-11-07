#include "Game.h"
#undef main

Game *game = nullptr;

int main(){
    
    const int FPS = 60;
    const int frameDelay = 1000/FPS;
    Uint32 frameStart;
    int frameTime;
    
    game = new Game();
    char title[] = "TheFinalBattle";
    
    game->init(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1400, 800, false);
    
    while (game->running()) {
        
        frameStart = SDL_GetTicks();
        
        game->events();
        game->update();
        game->render();
        
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }
    
    game->clean();
	return 0;
}
