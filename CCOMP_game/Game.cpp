// Game cpp
#include "Game.h"

Game::Game()
{}
Game::~Game()
{}

void Game::init(char *title, int x, int y, int width, int height, bool fullscreen){
    int full = 0;
    if (fullscreen){
        full = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING)==0){
        std::cout<<"Everething ok.. for now :v"<<std::endl;
        window = SDL_CreateWindow(title, x, y, width, height, full);
        if(window){
            std::cout<<"Window active!"<<std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout<<"Render active!"<<std::endl;
        }
        runningNow = true;
    }
    else{
        runningNow = false;
    }
}

void Game::events(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            runningNow = false;
            break;
        default:
            break;
    }
}

void Game::update(){
    //cnt ++;
    //std::cout<<cnt<<std::endl;
}

void Game::render(){
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<<"Everthing close! :v"<<std::endl;
}

bool Game::running(){
    return runningNow;
}


