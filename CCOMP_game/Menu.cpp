#include "Menu.h"
#include "Colisions.h"
#include "Button.h"
#include "TextureManager.h"

Boton *buton1;
Boton *buton2;
Messages *messages1;

void Menu::setStart(){
    buton1 = new Boton(600, 200, 200 , 150 ,TextureManager::loadVec("assets/buttons/inputS.txt",2), 600);
    buton2 = new Boton(400, 500, 600 , 150 ,TextureManager::loadVec("assets/buttons/inputI.txt",2), 600);
    messages1 = new Messages(500,10,400,100,"THE FINAL BATTLE",50);
    background = TextureManager::loadTexture("assets/background.jpg");
    recWindow.x=0; recWindow.y=0; recWindow.h=800; recWindow.w=1400;
}


void Menu::verify(){
    buton1->Check();
    buton2->Check();
    if (buton1->mousePress()) {
        runningNow=false;
        exit=false;
    }
}

void Menu::render() {
    SDL_RenderClear(renderer);
    TextureManager::Draw(background,recWindow);
    messages1->update_msg();
    buton1->Render(buton1->gettick());
    buton2->Render(buton2->gettick());
    SDL_RenderPresent(renderer);
}

void Menu::clearing(){
    messages1->cleari();
}

void Menu::events() {
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            runningNow = false;
            break;
        default:
            break;
    }
}
