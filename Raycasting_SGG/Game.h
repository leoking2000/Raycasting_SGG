#pragma once
#include "Camera.h"
#include "GameSettings.h"

// a class to hold the game state and logic
class Game
{
public:
	///////////Initialization and Destruction///////////
	Game();
	~Game();
	Game(const Game& g) = delete;
	Game& operator=(const Game& g) = delete;
	///////////////Static Constexpr Data//////////////////
	///////////////Special Functions//////////////////////
	void Update();
	void Draw();
private:
	//////////Game Functions/////////////////////////////
	
private:
	//////////////Game variables/////////////////////////
	Scene scene;
	Camera camera;

};
