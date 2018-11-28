#ifndef buffs_h
#define buffs_h
#include "GameObject.h"
#include <vector>

class Buff : public GameObject{
public:
    int direction;
    bool show;
    Buff(){}
    Buff(int x, int y, int h, int w, std::vector<SDL_Texture*> sp,int idd, int dir) : GameObject(x,y,h,w,sp,idd){
        direction = dir;
        show=true;
    }
    
    void UpdatePos(int a, int b){
        destRect.x += a;
        destRect.y += b;
    }
};

#endif /* buffs_h */

