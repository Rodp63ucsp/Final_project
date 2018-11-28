#include "Window.h"
#include <iostream>

SDL_Renderer* Window::renderer = nullptr;
SDL_Event Window::event;

void Window::init(const char *title, int x, int y, int width, int height, bool fullscreen){
    int full = 0;
    if (fullscreen) {
        full = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(title, x, y, width, height, full);
        renderer = SDL_CreateRenderer(window, 0, 0);
        runningNow = true;
        std::cout << "Everething ok.. for now :v" << std::endl;
    }
    else std::cout<<"Error!!!!"<<'\n';
}

void Window::clean(){
    SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
    std::cout << "Everthing close! :v" << std::endl;
}

