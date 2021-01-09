#pragma once
#include "Item.h"

class ItemHolder : public GameObject
{
public:
	virtual Item* GetItem() = 0;
	void virtual SetItem(Item* item) = 0;
};
