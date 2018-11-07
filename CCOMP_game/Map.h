#ifndef Map_h
#define Map_h
#include "Game.h"
#include <vector>

class Map {
public:
	Map();
	~Map();
	void LoadMap(std::vector<std::vector<int> >);
	void DrawMap();

private:
	SDL_Rect src, dest;
	SDL_Texture* grass;
	SDL_Texture* stone;
	SDL_Texture* lava;
	SDL_Texture* water;
    SDL_Texture* mud;
	int map[20][35];
	std::vector<std::vector<int> > readMap(const char*);

};


#endif /* Map_hpp */
