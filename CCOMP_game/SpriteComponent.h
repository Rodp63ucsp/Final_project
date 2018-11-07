#pragma once

#include "Components.h"
#include "SDL2/SDL.h"
#include "TextureManager.h"

class SpriteComponent : public Component {
private:
	PositionComponent *transform;
	SDL_Texture *texture;
	SDL_Rect srcRect, destRect;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path) {
		setTex(path);
	}

	~SpriteComponent() {
		SDL_DestroyTexture(texture);
	}

	void clear() {
		SDL_DestroyTexture(texture);
	}

	void setTex(const char *path) {
        texture = TextureManager::loadTexture(path);
	}

	void init() {
		transform = &entity->getComponent<PositionComponent>();

		srcRect.x = transform->position.x;
		srcRect.y = transform->position.y;
		srcRect.w = transform->width;
		srcRect.h = transform->height;

		transform->scale = 2;
		transform->speed = 2;
	
		destRect.w = destRect.h = 64;

	}
	void update() {
		destRect.x = static_cast<int>(transform->position.x);
		destRect.y = static_cast<int>(transform->position.y);
		destRect.w = transform->width*transform->scale;
		destRect.h = transform->height*transform->scale;
	}
	void draw() {
		TextureManager::Draw(texture, destRect);
	}
};
