#pragma once
#include "GameObject.h"

class Item : public GameObject
{
public:

protected:
	void virtual Onpickup() = 0;
	void virtual OnUse() = 0;

};
