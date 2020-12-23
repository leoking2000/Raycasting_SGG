#pragma once
#include "Array2D.h"
#include "Player.h"
#include <string>
#include <vector>

class Level
{
public:
	Level(const std::string& filename);

	void Load(const std::string& filename);
	void Update();

	char Get(int x, int y) const;
	int GetWidth() const;
	int GetHeight() const;

	const Player& GetPlayer() const;
	const std::vector<GameObject*>& GameObjects() const;

private:
	int width;
	int height;
	Array2D<char> arr;
	Player player;
	std::vector<GameObject*> gameobjects;

private:
	void Set(int x, int y, char v);


};

