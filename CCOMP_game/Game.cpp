// Game cpp
#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "SpriteComponent.h"
#include "PositionComponent.h"
#include "Vector2d.h"
#include "Keyboard.h"
#include "Collision.h"
#include "ColliderComponent.h"

Map* mapa;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

Manager manager;
auto& newPlayer(manager.addEntity());
auto& newPlayer2(manager.addEntity());
auto& wall(manager.addEntity());

/*Game::Game()
{}
Game::~Game()
{}*/

void Game::init(char *title, int x, int y, int width, int height, bool fullscreen) {
	int full = 0;
	if (fullscreen) {
		full = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Everething ok.. for now :v" << std::endl;
		window = SDL_CreateWindow(title, x, y, width, height, full);
		if (window) {
			std::cout << "Window active!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Render active!" << std::endl;
		}
		runningNow = true;
	}

	mapa = new Map();

	wall.addComponent<PositionComponent>(300,300,20,20,1,0);
	wall.addComponent<SpriteComponent>("assets/mud.png");
	wall.addComponent<ColliderComponent>("wall");

	newPlayer.addComponent<PositionComponent>(50,750,25,25,2,2);
	newPlayer.addComponent<SpriteComponent>("assets/Player1/1f.png");
	newPlayer.addComponent<Keyboard>(true);
	newPlayer.addComponent<ColliderComponent>("player");
    
    newPlayer2.addComponent<PositionComponent>(1300,50,25,25,2,2);
    newPlayer2.addComponent<SpriteComponent>("assets/Player1/4f.png");
    newPlayer2.addComponent<Keyboard>(false);
    newPlayer2.addComponent<ColliderComponent>("player");

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
	manager.refresh();
	//Estaba intentando para que para la dirección que se mueva cambie de imagen :"V 
	//Si quitas "/*" del if de abajo y  lo corres entenderas 
	//Si PUEDES arreglalo
	
	if (Game::event.type == SDL_KEYDOWN) {
		switch (Game::event.key.keysym.sym) {
		case SDLK_w:
			//newPlayer.addComponent<SpriteComponent>();
			newPlayer.addComponent<SpriteComponent>("assets/player1/3f.png");
                newPlayer.update(); newPlayer.draw();
            newPlayer.addComponent<SpriteComponent>("assets/player1/3l.png");
                newPlayer.update(); newPlayer.draw();
            newPlayer.addComponent<SpriteComponent>("assets/player1/3r.png");
                newPlayer.update(); newPlayer.draw();
			break;
		case SDLK_s:
			//newPlayer.addComponent<SpriteComponent>();
			newPlayer.addComponent<SpriteComponent>("assets/player1/1f.png");
			break;
		case SDLK_a:
			//newPlayer.addComponent<SpriteComponent>();
			newPlayer.addComponent<SpriteComponent>("assets/player1/2f.png");
			break;
		case SDLK_d:
			//newPlayer.addComponent<SpriteComponent>();
			newPlayer.addComponent<SpriteComponent>("assets/player1/4f.png");
			break;
		default:
			break;
		}
	}

	if(Collision::AABB(newPlayer.getComponent<ColliderComponent>().collider,wall.getComponent<ColliderComponent>().collider)){
		std::cout << "CHOQUE"  ;
	}

    manager.update();
}

void Game::render() {
	SDL_RenderClear(renderer);
	mapa->DrawMap();
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Everthing close! :v" << std::endl;
}


