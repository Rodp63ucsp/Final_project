#pragma once
#include "Game.h"					
#include "ECS.h"
#include "Components.h"
#include "PositionComponent.h"
#include "SpriteComponent.h"

class Keyboard : public Component{
private:
    bool player;
public:
    Keyboard(bool t) : player(t) {}
	PositionComponent *transform;

	void init() {
		transform = &entity->getComponent<PositionComponent>();
	}

	void update() {
		if (Game::event.type == SDL_KEYDOWN && player) {
			switch (Game::event.key.keysym.sym) {
			case SDLK_w:
				transform->movement.y = -0.5;
				break;
			case SDLK_s:
				transform->movement.y = 0.5;
				break;
			case SDLK_a:
				transform->movement.x = -0.5;
				break;
			case SDLK_d:
				transform->movement.x = 0.5;
				break;
			default:
				break;
			}
		}
        if (Game::event.type == SDL_KEYDOWN && !player) {
            switch (Game::event.key.keysym.sym) {
                case SDLK_UP:
                    transform->movement.y = -0.5;
                    break;
                case SDLK_DOWN:
                    transform->movement.y = 0.5;
                    break;
                case SDLK_LEFT:
                    transform->movement.x = -0.5;
                    break;
                case SDLK_RIGHT:
                    transform->movement.x = 0.5;
                    break;
                default:
                    break;
            }
        }
		if (Game::event.type == SDL_KEYUP) {
			transform->movement.y = 0;
			transform->movement.x = 0;
		}
	}

};

