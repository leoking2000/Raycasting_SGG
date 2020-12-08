#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(const Vector2& pos, const Vector2& dir)
		:
		Entity(pos,dir)
	{
	}

	graphics::Brush getBrush() const override
	{
		// the player will never been drawn

		return graphics::Brush();
	}

	void Update(float dt) override;

};

