#pragma once
#include "Array2D.h"
#include "IHasHealth.h"
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
	Level(const Level& g) = delete;
	Level& operator=(const Level& g) = delete;

	bool Load(const std::string& filename);
	Event Update();

	char Get(int x, int y) const;
	int GetWidth() const;
	int GetHeight() const;

	const IHasHealth* const GetPlayer() const;
	const std::vector<GameObject*>& GameObjects() const;

	void AddGameObject(GameObject* go);
	void KeyPickUp();
	int GetNumOfkeys() const;

private:
	int width;
	int height;
	Array2D<char> arr;
	IHasHealth* player;
	std::vector<GameObject*> gameobjects;

	const float deletionPeriod; // in milliseconds
	float timePassed = 0;

	int numOfkeys = 0;

private:
	void Set(int x, int y, char v);
	void DeleteDeadGameObjects();
	void Free();

};

