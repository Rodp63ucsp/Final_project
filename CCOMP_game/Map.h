#ifndef Map_h
#define Map_h
#include "brick.h"
#include <vector>

class Map {
public:
    Map(bool st);
    ~Map();
    std::vector<std::vector<Brick*> > bricks;
    void LoadMap(std::vector<std::vector<int> >);
    void DrawMap();
    void Update();
    void Check(std::vector<int> &v,SDL_Rect);
    
private:
    SDL_Texture* grassL;
    SDL_Texture* grassR;
    SDL_Texture* stone;
    std::vector<SDL_Texture*> lava;
    std::vector<SDL_Texture*> water;
    SDL_Texture* mud;
    int map[20][35];
    std::vector<std::vector<int> > readMap(const char*);
    
};


#endif /* Map_hpp */

