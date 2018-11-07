#ifndef Game_h
#define Game_h

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include <vector>
#include <iostream>



class Game{
public:

    void init(char *title, int x, int y, int width, int height, bool fullscreen);
    void events();
    void update();
    void render();
    bool running(){return runningNow;};
    void clean();
    static SDL_Renderer* renderer;
	static SDL_Event event;
	

private:
    int cnt = 0;
    bool runningNow = false;
    SDL_Window *window;
};

#endif /* Game_h */
