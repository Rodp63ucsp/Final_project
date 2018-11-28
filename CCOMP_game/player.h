#pragma once
#include <iostream>
#include "GameObject.h"
#include "TextureManager.h"
#include "buffs.h"
#include <vector>
#include <stdlib.h>
using namespace std;

class Player : public GameObject {
public:
    
    double vel=1, speed = 1; float ticksoul;
    bool live=true, gunactive=true;
    vector<SDL_Texture*> soul;
    vector<Buff*> bullets;
    
    Player(int _x, int _y, int _w, int _h, vector<SDL_Texture*> sp, int idd, bool selectplayer) : GameObject(_x, _y, _w, _h, sp, idd) {
        selectPlayer = selectplayer;
        xOrigin = _x;
        yOrigin = _y;
    }
    
    bool Find(int num){
        for(int i=0; i<colisions.size(); i++){
            if(colisions[i]==num) return true;
        }
        return false;
    }
    
    void State(){
        if(Find(3) || Find(8) || Find(13) || Find(18)){
            live = false;
            if(soul.size()==0) soul = TextureManager::loadVec("assets/soul/input.txt",8); //Lazy initialization
        }
        if(Find(300)) {cout<<"You win!!!"<<endl;}
        colisions = vector<int>(0);
        for(int i=0; i<bullets.size(); i++){
            switch (bullets[i]->direction) {
                case 1:
                    bullets[i]->UpdatePos(-5,0); break;
                case 2:
                    bullets[i]->UpdatePos(0,-5); break;
                case 0:
                    bullets[i]->UpdatePos(0,5); break;
                default:
                    bullets[i]->UpdatePos(5,0); break;
            }
            
        }
    }
    
    void respawn(){
        destRect.y -= 4;
        ticksoul+=0.1; if(ticksoul>=8) ticksoul=0;
        Render(ticksoul,soul);
        if(destRect.y<-30) {
            destRect.x = xOrigin;
            destRect.y = yOrigin;
            tmp = 0;
            live=true;
        }
    }
    
    void shoot(){
        vector<SDL_Texture*> temp;
        temp.push_back(sprites[sprites.size()-1]);
        bullets.push_back(new Buff(destRect.x+5,destRect.y+5,25,25,temp,600,tmp));
        cout<<"Shoot"<<endl;
    }
    
    void Drawshoots(){
        for(int i=0; i<bullets.size(); i++){
            if(bullets[i]->show) bullets[i]->Render(0);
            SDL_Rect poss = bullets[i]->getdest();
            if(poss.x>1400 || poss.x<0 || poss.y<0 || poss.y>800){
                bullets.erase(bullets.begin()+i);
            }
        }
    }
    
    void Assesinate(vector<Buff*> &v){
        for(int i=0; i<v.size(); i++){
            v[i]->Verify(colisions, destRect, 0, 0, 0, 0);
        }
        if(Find(600) || Find(605) || Find(610) || Find(615)){
            live = false;
            if(soul.size()==0) soul = TextureManager::loadVec("assets/soul/input.txt",8);
        }
    }
    
    
    void keyboard() {
        speed += 1;
        if(speed>=2) speed=vel;
        if (!selectPlayer) {
            
            if(Find(10) || Find(15) || Find(20)) vel = 0;
            else vel=1;
            
            if (Game::event.type == SDL_KEYDOWN) {
                switch (Game::event.key.keysym.sym) {
                    case SDLK_DOWN:
                        tmp = 0;
                        if(!Find(12) && destRect.y<760) destRect.y += (int(speed)%2);
                        Render(0+extratick);
                        break;
                    case SDLK_UP:
                        tmp = 2;
                        if(!Find(2) && destRect.y>0) destRect.y -= (int(speed)%2);
                        Render(6+extratick);
                        return;
                    case SDLK_LEFT:
                        tmp = 1;
                        if(!Find(7)) destRect.x -= (int(speed)%2);
                        Render(3+extratick);
                        break;
                    case SDLK_RIGHT:
                        tmp = 3;
                        if(!Find(17)) destRect.x += (int(speed)%2);
                        Render(9+extratick);
                        break;
                    case SDLK_SPACE:
                        if(gunactive) {
                            shoot();
                            //gunactive=false;
                        } break;
                    default:
                        if (tmp == 0) Render(0);
                        if (tmp == 1) Render(3);
                        if (tmp == 2) Render(6);
                        if (tmp == 3) Render(9);
                        break;
                }
            }
            else {
                if (tmp == 0) Render(0);
                if (tmp == 1) Render(3);
                if (tmp == 2) Render(6);
                if (tmp == 3) Render(9);
            }
        }
        else {
            
            if(Find(10) || Find(15) || Find(20)) vel = 0;
            else vel=1;
            
            const Uint8 *state = SDL_GetKeyboardState(NULL);
            if (state[SDL_SCANCODE_W]) {
                tmp = 2;
                if(!Find(2) && destRect.y>0) destRect.y -= (int(speed)%2);
                Render(6+extratick);
            }
            else if(state[SDL_SCANCODE_S]){
                tmp = 0;
                if(!Find(12) && destRect.y<760) destRect.y += (int(speed)%2);
                Render(0+extratick);
            }
            else if(state[SDL_SCANCODE_D]){
                tmp = 3;
                if(!Find(17)) destRect.x += (int(speed)%2);
                Render(9+extratick);
            }
            else if(state[SDL_SCANCODE_A]){
                tmp = 1;
                if(!Find(7)) destRect.x -= (int(speed)%2);
                Render(3+extratick);
            }
            else if(Game::event.type == SDL_KEYDOWN && Game::event.key.keysym.sym==SDLK_q){
                if(gunactive) {
                    shoot();
                    //gunactive=false;
                }
            }
            else{
                if (tmp == 0) Render(0);
                if (tmp == 1) Render(3);
                if (tmp == 2) Render(6);
                if (tmp == 3) Render(9);
            }
        }
    }
    
private:
    bool selectPlayer;
    int xOrigin;
    int yOrigin;
    int tmp = 0;
};
