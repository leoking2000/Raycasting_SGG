#pragma once
#include "Vector2.h"

class Player
{
public:
	Player(const Vector2& pos);

	Vector2 Position() const;
	Vector2	Direction() const;

	void GoForward(float v);
	void RotateBy(float rad);

private:
	Vector2 position;           // world space
	Vector2 direction{ -1,0 };  // world space

};

