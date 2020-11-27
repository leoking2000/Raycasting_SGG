#pragma once
#include "Camera.h"

// a class to hold the game state and logic
class Game
{
public:
	///////////Initialization and Destruction///////////
	Game();
	~Game();
	Game(const Game& g) = delete;
	Game& operator=(const Game& g) = delete;
	///////////////Static Constexpr Data////////////////////////
	static constexpr unsigned int CanvasWidth = 1600u;
	static constexpr unsigned int CanvasHeight = 900u;
	///////////////Special Functions//////////////////////
	void Update(float dt);
	void Draw();
private:
	//////////Game Functions/////////////////////////////
	
private:
	//////////////Game variables/////////////////////////
	Scene scene;
	Camera camera;

};
