#ifndef Button_h
#define Button_h
#include "GameObject.h"
#include "TextureManager.h"
#include "Colisions.h"
#include <vector>

class Boton : public GameObject{
public:
    Boton(int x, int y, int w,int h,std::vector<SDL_Texture*> sp,int idd) : GameObject(x,y,h,w,sp,idd){}
    
    void Check() {
        SDL_PollEvent(&Menu::event);
        switch (Menu::event.type) {
            case SDL_MOUSEMOTION:
                if (Colision::pressbutton(destRect, Menu::event.motion.x, Menu::event.motion.y)) extratick=1;
                    else extratick=0;
                break;
        }
    }
    
    bool mousePress(SDL_MouseButtonEvent& b=Menu::event.button) {
        if (b.button == SDL_BUTTON_LEFT && Colision::pressbutton(destRect,Menu::event.motion.x,Menu::event.motion.y)) {
            return true;
        }
        return false;
    }
    
};

class Messages {
    SDL_Surface* message;
    SDL_Color textcolor;
    TTF_Font *font;
    SDL_Texture* text;
    SDL_Rect message_rect;
    
public:
    Messages(int x, int y, int w, int h, const char* msages, int tam){
        font = TTF_OpenFont("arial.ttf", tam);
        if(!font) std::cout<<"FAil!!!"<<std::endl;
        else std::cout << "CARGO" << std::endl;
        textcolor = { 255,255,255 };
        message = TTF_RenderText_Solid(font, msages, textcolor);
        text = SDL_CreateTextureFromSurface(Menu::renderer, message);
        message_rect.x = x;
        message_rect.y = y;
        message_rect.h = h;
        message_rect.w = w;
    }
    
    void update_msg(){
        SDL_RenderCopy(Menu::renderer, text, NULL, &message_rect);
    }
    void cleari(){
        SDL_DestroyTexture(text);
        SDL_FreeSurface(message);
        TTF_CloseFont(font);
        //    TTF_Quit();
    }
};

#endif /* Button_h */

