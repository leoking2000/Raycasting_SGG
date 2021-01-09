#pragma once
#include "GameObject.h"

class Item : public GameObject
{
public:
	void virtual Onpickup(GameObject& user) = 0;
	void virtual OnUse() = 0;

};
