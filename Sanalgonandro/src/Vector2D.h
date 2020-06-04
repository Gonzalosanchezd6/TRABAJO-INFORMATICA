#pragma once

class Vector2D {
public:
	float x;
	float y;
public:
	Vector2D(float xv = 0.0f, float yv = 0.0f);
	virtual ~Vector2D();

	float modulo(); //modulo del vector
	float argumento(); //argumento del vector
	Vector2D Unitario(); //devuelve un vector unitario
	Vector2D operator - (Vector2D &); //resta de vectores
	Vector2D operator + (Vector2D &); //suma de vectores
	float operator *(Vector2D &); //producto escalar
	Vector2D operator *(float num); //producto por un escalar

	friend bool operator==(const Vector2D& v1, const Vector2D& v2);
};