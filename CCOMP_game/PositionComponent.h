#pragma once
#include "ECS.h"
#include "Vector2d.h"

class PositionComponent : public Component{
public:

	Vector2d position;
	Vector2d movement;

	int height = 40;
	int width = 40;
	double scale = 1.5;
    double speed;

	PositionComponent() {
		position.x = 0;
		position.y = 0;
		height = 32;
		width = 32;
		scale = 1;

		speed = 3;
	}

	PositionComponent(float xh,float yk) {
		position.x = xh;
		position.y = yk;
	}

	PositionComponent(float xh, float yk,int w,int h,double sc, double sp) {
		position.x = xh;
		position.y = yk;
		height = h;
		width = w;
		scale = sc;
		speed = sp;
	}

	void update() {
		position.x += movement.x*speed;
		position.y += movement.y*speed;
	}


	
};
