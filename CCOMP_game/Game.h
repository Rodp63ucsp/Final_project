// render general
#ifndef Game_h
#define Game_h
#include <SDL2/SDL.h>
#include <iostream>

class Game{
public:
    Game();
    ~Game();
    void init(char *title, int x, int y, int width, int height, bool fullscreen);
    void events();
    void update();
    void render();
    bool running();
    void clean();
private:
    int cnt = 0;
    bool runningNow;
    SDL_Window *window;
    SDL_Renderer *renderer;
};


#endif /* Game_h */
