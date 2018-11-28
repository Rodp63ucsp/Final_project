#ifndef brick_h
#define brick_h
#include "GameObject.h"
#include <vector>

class Brick : public GameObject{
public:
    Brick(int x, int y, std::vector<SDL_Texture*> sp,int idd) : GameObject(x,y,40,40,sp,idd){}
    //ID 1 2 3 4 5
    //u 1 2 3 4 5
    //l 6 7 8 9 10
    //d 11 12 13 14 15
    //r 16 17 18 19 20

};

#endif /* brick_h */
