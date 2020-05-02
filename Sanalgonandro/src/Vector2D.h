#pragma once

class Vector2D {
public:
	float x;
	float y;
public:
	Vector2D(float xv = 0.0f, float yv = 0.0f);//constructor
	virtual ~Vector2D();//destructor

	float modulo(); // (2) modulo del vector
	float argumento(); // (3) argumento del vector
	Vector2D Unitario(); // (4) devuelve un vector unitario
	Vector2D operator - (Vector2D &); // (5) resta de vectores
	Vector2D operator + (Vector2D &); // (6) suma de vectores
	float operator *(Vector2D &); // (7) producto escalar
	Vector2D operator *(float num); // (8) producto por un escalar

	friend bool operator==(const Vector2D& v1, const Vector2D& v2);
};