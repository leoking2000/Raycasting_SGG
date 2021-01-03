#pragma once
#include "GameObject.h"

/// <summary>
///
/// </summary>
class Item : public GameObject
{
public:
	void virtual OnPikingUp() = 0; // is called when an entity is picking up the item from the ground.
	void virtual OnUse() = 0;      // is called when the entity is using the item.
};
