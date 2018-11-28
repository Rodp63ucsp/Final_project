#include "Map.h"
#include "TextureManager.h"
#include "brick.h"
#include "Colisions.h"
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

Map::Map(bool st) {
    if(st){
        grassL = TextureManager::loadTexture("assets/floorR.png");
        grassR = TextureManager::loadTexture("assets/floorL.png");
        stone = TextureManager::loadTexture("assets/wall1.png");
    }
    else{
        grassL = TextureManager::loadTexture("assets/grassL.png");
        grassR = TextureManager::loadTexture("assets/grassR.png");
        stone = TextureManager::loadTexture("assets/wall2.png");
    }
    lava = TextureManager::loadVec("assets/lava/input.txt", 32);
    water = TextureManager::loadVec("assets/water/input.txt", 6);
    mud = TextureManager::loadTexture("assets/mud.png");
    matrix temp = readMap("Levels/lvl1.txt");
    LoadMap(temp);
}

Map::~Map() {
}

void Map::LoadMap(matrix tmp) {
    for (int i = 0; i < 20; i++) {
        vector<Brick*> colum;
        for (int j = 0; j < 35; j++) {
            map[i][j] = tmp[i][j];
            vector<SDL_Texture*> temp;
            int idd = 0;
            switch (tmp[i][j]) {
                case 0:
                    temp.push_back(grassL); idd=1; break;
                case 1:
                    temp.push_back(stone); idd=2; break;
                case 2:
                    temp = lava; idd=3; break;
                case 3:
                    temp = water; idd=4; break;
                case 4:
                    temp.push_back(mud); idd=5; break;
                case 5:
                    temp.push_back(grassR); idd=1; break;
            }
            temp.push_back(grassL);
            colum.push_back(new Brick(j*40,i*40,temp,idd));
        }
        bricks.push_back(colum);
    }
}

void Map::DrawMap() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 35; j++) {
            switch (map[i][j]) {
                case 2:
                    bricks[i][j]->Render(bricks[i][j]->gettick()); break;
                case 3:
                    bricks[i][j]->Render(bricks[i][j]->gettick()); break;
                default:
                    bricks[i][j]->Render(0); break;
            }
        }
    }
}

void Map::Update(){
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 35; j++) {
            switch (map[i][j]) {
                case 2:
                    bricks[i][j]->Update(31,0.3); break;
                case 3:
                    bricks[i][j]->Update(5,0.2); break;
            }
        }
    }
}

void Map::Check(vector<int> &v, SDL_Rect recB){
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 35; j++) {
            bricks[i][j]->Verify(v,recB,0,0,15,20);
        }
    }
}

