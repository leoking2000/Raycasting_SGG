#pragma once

class Item;

class ItemHolder
{
public:
	virtual Item* GetItem() = 0;
	void virtual SetItem(Item* item) = 0;
};
