#include "Vector2d.h"

#include <iostream>

Vector2d::Vector2d(){
	x = 0;	y = 0;
}

Vector2d::Vector2d(float xh, float yk) {
	x = xh;	y = yk;
}

Vector2d::~Vector2d()
{
}

Vector2d&Vector2d:: Add(const Vector2d& vec) {
	this->x += vec.x;
	this->y += vec.y;

	return *this;
}

Vector2d&Vector2d::Substract(const Vector2d& vec) {
	this->x -= vec.x;
	this->y -= vec.y;

	return *this;
}

Vector2d&Vector2d::Multiply(const Vector2d& vec) {
	this->x *= vec.x;
	this->y *= vec.y;

	return *this;
}

Vector2d&Vector2d::Divide(const Vector2d& vec) {
	this->x /= vec.x;
	this->y /= vec.y;

	return *this;
}

Vector2d operator+(Vector2d & v1, const Vector2d & v2)
{
	return v1.Add(v2);
}
Vector2d operator-(Vector2d& v1, const Vector2d& v2) {
	return v1.Substract(v2);
}
Vector2d operator*(Vector2d& v1, const Vector2d& v2) {
	return v1.Multiply(v2);
}
Vector2d operator/(Vector2d& v1, const Vector2d& v2) {
	return v1.Divide(v2);
}

std::iostream& operator <<(std::iostream& s, const Vector2d& v) {
	s << "(" << v.x << "," << v.y << ")";
	return s;
}


Vector2d& Vector2d::operator*(const int &i) {
	this->x *= 1;
	this->y *= 1;

	return *this;
}
