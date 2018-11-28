// Game cpp
#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "player.h"
#include "GameExtras.h"
#include <iostream>
#include <vector>

Map* mapa;
Player* player1;
Player* player2;
Buff* trophy;

void Game::setStart() {
    mapa = new Map(false);
    trophy = new Buff(650,325,100,100,TextureManager::loadVec("assets/trophy/input.txt", 10),300,0);
    player1 = new Player(32,750,42,55,TextureManager::loadVec("assets/player1/input.txt",13),100,true);
    player2 = new Player(1310,10,42,60,TextureManager::loadVec("assets/player2/input.txt",13),200,false);
    ExtrasManager::init();
}

void Game::events() {
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            runningNow = false;
            break;
        default:
            break;
    }
}

void Game::update() {
    trophy->Update(10,0.1);
    player1->Update(3,0.1);
    player2->Update(3,0.1);
    player1->State();
    player2->State();
    mapa->Update();
    ExtrasManager::getBuff(bufff);
    ExtrasManager::Update(bufff);
}

void Game::verify(){
    mapa->Check(player1->colisions, player1->getdest());
    mapa->Check(player2->colisions, player2->getdest());
    player1->Assesinate(player2->bullets);
    player2->Assesinate(player1->bullets);
    trophy->Verify(player1->colisions, player1->getdest(), 10, 30, 0, 0);
    ExtrasManager::Verify(bufff, player1->bullets);
    ExtrasManager::Verify(bufff, player2->bullets);
}

void Game::render() {
    SDL_RenderClear(renderer);
    mapa->DrawMap();
    trophy->Render(trophy->gettick());
    
    if(player1->live) player1->keyboard();
    else player1->respawn();
    if(player2->live) player2->keyboard();
    else player2->respawn();
    
    ExtrasManager::DrawBuffs(bufff);
    player1->Drawshoots();
    player2->Drawshoots();
    SDL_RenderPresent(renderer);
}
