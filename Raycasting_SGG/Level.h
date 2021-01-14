#pragma once
#include "Array2D.h"
#include "GameObject.h"
#include <string>
#include <vector>

enum Event
{
	NOTHING,
	PlayerDies,
	PlayerWin
};

class Level
{
public:
	Level();
	~Level();

	bool Load(const std::string& filename);
	Event Update();

	char Get(int x, int y) const;
	int GetWidth() const;
	int GetHeight() const;

	const GameObject* const GetPlayer() const;
	const std::vector<GameObject*>& GameObjects() const;
	void AddGameObject(GameObject* go);

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

