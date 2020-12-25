#pragma once
#include "GameObject.h"

/// <summary>
///
/// </summary>
class Item : public GameObject
{
public:
	Item(float xPos, float yPos, const std::string& texture)
		:
		GameObject(xPos,yPos, texture)
	{}

	//void virtual OnPikingUp(class Entity& user) = 0;
	//void virtual OnUse(class Entity& user) = 0;

	void Update() final override
	{
		if (isOnGround == false) return;

	};

protected:
	bool isOnGround = true;
	


};