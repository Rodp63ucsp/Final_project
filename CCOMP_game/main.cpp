#include "Game.h"
Game *game = nullptr;

int main(){
    game = new Game();
    char title[] = "Fight";
    game->init(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    while (game->running()) {
        game->events();
        game->update();
        game->render();
    }
    game->clean();
}
