#pragma once
#include "Camera.h"
#include "Level.h"

// a class to hold the game state and logic
class Game
{
public:
	///////////Initialization and Destruction///////////
	Game();
	~Game();
	Game(const Game& g) = delete;
	Game& operator=(const Game& g) = delete;
	//////////Getters Functions/////////////////////////////
	int CanvasWidth() const;
	int CanvasHeight() const;
	Level& GetLevel();
	///////////////Special Functions//////////////////////
	void Update();
	void Draw();
	void ResizeCanvas(int w, int h);
private:
	//////////Game Functions/////////////////////////////

	void UpdateMainMenu();
	void DrawMainMenu();

	void UpdatePlayScreen();
	void DrawPlayScreen();
private:
	enum State
	{
		MAINMENU,
		LEVELSELECTOR,
		PLAYSCREEN,
		DEATHSCREEN,
		WINSCREEN,
	};
private:
	//////////////Game variables/////////////////////////

	int canvaswidth = 1600;
	int canvasheight = 900;
	Level level;
	Camera camera;

	Game::State state = Game::State::MAINMENU;
};
