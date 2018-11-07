#pragma once
#include <string>
#include "Game.h"
#include "SDL2/SDL.h"
#include "ECS.h"
#include "PositionComponent.h"


class ColliderComponent :public Component{
public:
	SDL_Rect collider;
	std::string tag;

	PositionComponent *transform;

	ColliderComponent(std::string t) {
		tag = t;
	}

	void init() {
		/*if (!entity->hasComponent<PositionComponent>()) {
			entity->addComponent < PositionComponent > ();
		}*/
		//entity->addComponent < PositionComponent >();
		transform = &entity->getComponent < PositionComponent > ();

	}
	
	void update() override{
		collider.x = static_cast<int>(transform->position.x);
		collider.y = static_cast<int>(transform->position.y);
		collider.w = static_cast<int>(transform->width*transform->scale);
		collider.h = static_cast<int>(transform->height*transform->scale);
	}

};
