#include "GameObject.h"
#include "TextureManager.h"
#include "Colisions.h"

GameObject::GameObject(){}

GameObject::GameObject(int _x, int _y, int h, int w, std::vector<SDL_Texture*> sp, int idd){
    
    destRect.x = _x;
    destRect.y = _y;
    destRect.h = h;
    destRect.w = w;
    sprites = sp;
    ID = idd;
    
}

void GameObject::Update(int extra, float aum){
    
    extratick += aum; if(extratick>=extra) extratick=0;
    
}

void GameObject::Render(int frame){
    TextureManager::Draw(sprites[frame], destRect);
}

void GameObject::Render(int frame, std::vector<SDL_Texture*> &ss){
    TextureManager::Draw(ss[frame], destRect);
}

void GameObject::Verify(std::vector<int> &v, SDL_Rect recB, int a, int b, int c, int d){
    if(Colision::UpDownCol(destRect,recB,a,b,c,d)) v.push_back(ID); //Up
    if(Colision::LeftRightCol(destRect,recB,a,b,c,d)) v.push_back(ID+5); //Left
    if(Colision::UpDownCol(recB,destRect,c,d,a,b)) v.push_back(ID+10); //Down
    if(Colision::LeftRightCol(recB,destRect,c,d,a,b)) v.push_back(ID+15); //Right
}

SDL_Rect GameObject::getdest() {
    return destRect;
}

int GameObject::gettick(){
    return extratick;
}


