#ifndef Game_h
#define Game_h
#include "Window.h"
#include "buffs.h"

class Game : public Window{
public:
    
    void setStart();
    void events();
    void update();
    void render();
    void verify();
    
private:
    int sec, mins;
    std::vector<Buff*> bufff;
    
};

#endif /* Game_h */
