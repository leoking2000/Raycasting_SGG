#pragma once
#include "Array2D.h"
#include "GameObject.h"
#include <string>
#include <vector>

class Level
{
public:
	Level(const std::string& filename);
	~Level();

	void Load(const std::string& filename);
	void Update();

	char Get(int x, int y) const;
	int GetWidth() const;
	int GetHeight() const;

	const GameObject* const GetPlayer() const;
	const std::vector<GameObject*>& GameObjects() const;

private:
	int width;
	int height;
	Array2D<char> arr;
	GameObject* player;
	std::vector<GameObject*> gameobjects;

	const float deletionPeriod; // in milliseconds
	float timePassed = 0;

private:
	void Set(int x, int y, char v);
	void DeleteDeadGameObjects();
	void Free();

};

