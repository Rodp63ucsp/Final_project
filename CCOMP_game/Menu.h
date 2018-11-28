#ifndef Menu_hpp
#define Menu_hpp
#include "Window.h"
#include <iostream>

class Menu : public Window {
public:
    void setStart();
    void events();
    void render();
    void verify();
    void clearing();
    bool exit = true;
    
private:
    SDL_Rect recWindow;
    SDL_Texture* background;
};
#endif /* Menu_hpp */
