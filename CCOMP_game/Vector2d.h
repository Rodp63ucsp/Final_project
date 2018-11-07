#pragma once
#include <iostream>

class Vector2d{

public:

	float x, y;

	Vector2d();
	Vector2d(float,float);
	~Vector2d();

	/*float x(void);
	float y(void);*/

	Vector2d& Add(const Vector2d& vec);
	Vector2d& Substract(const Vector2d& vec);
	Vector2d& Multiply(const Vector2d& vec);
	Vector2d& Divide(const Vector2d& vec);

	Vector2d& operator+=(const Vector2d&);
	Vector2d& operator-=(const Vector2d&);
	Vector2d& operator*=(const Vector2d&);
	Vector2d& operator/=(const Vector2d&);

	Vector2d& operator*(const int &);

	friend std::iostream& operator <<(std::iostream&, const Vector2d&);
};