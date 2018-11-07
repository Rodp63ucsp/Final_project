#include "Map.h"
#include "TextureManager.h"
#include <vector>
#include <fstream>
using namespace std;
typedef vector<vector<int> > matrix;

matrix Map::readMap(const char* txt) {
	ifstream inputFile;
	inputFile.open(txt);
	matrix m(20, vector<int>(35, 1));
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 35; j++) {
			inputFile >> m[i][j];
		}
	}
	inputFile.close();
	return m;
}

Map::Map() {
	grass = TextureManager::loadTexture("assets/grass.png");
	stone = TextureManager::loadTexture("assets/stone.png");
	lava = TextureManager::loadTexture("assets/lava.png");
	water = TextureManager::loadTexture("assets/water.png");
    mud = TextureManager::loadTexture("assets/mud.png");
	matrix temp = readMap("Levels/lvl1.txt");
	LoadMap(temp);
	src.x = src.y = 0;
	dest.w = dest.h = 40;
	src.x = src.y = 0;
}

Map::~Map() {
}

void Map::LoadMap(matrix tmp) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 35; j++) {
			map[i][j] = tmp[i][j];
		}
	}
}

void Map::DrawMap() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 35; j++) {
			int type = map[i][j];
			dest.x = j * 40;
			dest.y = i * 40;
			switch (type) {
			case 0:
				TextureManager::Draw(grass, dest);
				break;
			case 1:
				TextureManager::Draw(stone, dest);
				break;
			case 2:
				TextureManager::Draw(lava, dest);
				break;
			case 3:
				TextureManager::Draw(water, dest);
				break;
            case 4:
                TextureManager::Draw(mud, dest);
                break;
			}
		}
	}
}


