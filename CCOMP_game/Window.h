#ifndef Window_hpp
#define Window_hpp

#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"
#include "SDL2_mixer/SDL_mixer.h"

class Window { //DEcorate
    
protected:
    bool runningNow = false;
    SDL_Window *window;
//    Mix_Music *music;

    
public:
    void init(const char *title, int x, int y, int width, int height, bool fullscreen);
    void clean();
    bool running(){return runningNow;};
    virtual void setStart() = 0;
    
    static SDL_Renderer* renderer;
    static SDL_Event event;

};

#endif /* Window_hpp */
