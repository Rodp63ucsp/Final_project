#include "GameExtras.h"
#include "TextureManager.h"
#include "Colisions.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#define FinD(v) v[i]==600 ||v[i]==605 || v[i]==610 || v[i]==615
using namespace std;

void ExtrasManager::init(){
    srand (time(NULL));
}

void ExtrasManager::getBuff(vector<Buff*> &v){
    int a = rand() % 1000;
    if(a<2){
        cout<<"New buff"<<endl;
        int x = rand() % 1300;
        int y = rand() % 700;
        if(v.size()<10) v.push_back(new Buff(x,y,45,40,TextureManager::loadVec("assets/frog/input.txt", 11),400,0));
    }
}

void ExtrasManager::DrawBuffs(vector<Buff*> &v){
    for(int i=0; i<v.size(); i++){
        if(v[i]->show) v[i]->Render(v[i]->gettick());
        for(int j=0; j<v[i]->colisions.size(); j++){
            if(FinD(v[i]->colisions))
                v[i]->show=false;
        }
    }
}

void ExtrasManager::Update(std::vector<Buff *> &v){
    for(int i=0; i<v.size(); i++){
        v[i]->Update(11, 0.2);
    }
}

void ExtrasManager::Verify(std::vector<Buff *> &v, std::vector<Buff*> &bull){
    for(int i=0; i<bull.size(); i++){
        for(int j=0; j<v.size(); j++){
            bull[i]->Verify(v[j]->colisions, v[j]->getdest(), 5, 5, 5, 5);
            if(Colision::LeftRightCol(v[j]->getdest(), bull[i]->getdest(), 0, 0, 0, 0)||
               Colision::UpDownCol(v[j]->getdest(), bull[i]->getdest(), 0, 0, 0, 0)){
                bull[i]->show=false;
            }
        }
    }
    for(int i=0; i<v.size(); i++){
        if(!v[i]->show) v.erase(v.begin()+i);
    }
}

