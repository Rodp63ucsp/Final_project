#ifndef Colisions_h
#define Colisions_h
#include <SDL2/SDL.h>

class Colision{
public:
    static bool UpDownCol(SDL_Rect recA, SDL_Rect recB, int a, int b, int c, int d){
        recA.x += b; recA.w -= (2*b); recA.y += a; recA.h -= (a+2);
        recB.x += d; recB.w -= (2*d); recB.y += c; recB.h -= (c+2);
        if( (recB.y) <= (recA.y+recA.h) &&
           (recB.y) >= (recA.y) &&
           (recA.x) < (recB.x+recB.w) &&
           (recA.x+recA.w) > (recB.x)
           ) return true;
        return false;
    }
    
    static bool LeftRightCol(SDL_Rect recA, SDL_Rect recB, int a, int b, int c, int d){
        recA.x += b; recA.w -= (2*b); recA.y += a; recA.h -= (a+2);
        recB.x += d; recB.w -= (2*d); recB.y += c; recB.h -= (c+2);
        if( (recB.x) <= (recA.x+recA.w) &&
           (recB.x) >= (recA.x) &&
           (recA.y) < (recB.y+recB.h) &&
           (recA.y+recA.h) > (recB.y)
           ) return true;
        return false;
    }
    
    static bool pressbutton(SDL_Rect recA,double butonX,double butonY) {
        if (butonX >= recA.x &&
            butonX <= (recA.x+recA.w) &&
            butonY >= recA.y &&
            butonY <= (recA.y+recA.h))
            return true;
        return false;
    }
};
#endif /* Colisions_h */
