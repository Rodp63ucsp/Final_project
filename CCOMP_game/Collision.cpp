#include "Collision.h"
//#include "ColliderComponent.h"

bool Collision::AABB(const SDL_Rect& recA, const SDL_Rect& recB) {
	if (recA.x + recA.w >= recB.x &&
		recA.y + recA.h >= recB.y &&
		recB.y + recB.h >= recA.y &&
		recB.x + recB.w >= recA.x ) {
		return true;
	}
	return false;
}