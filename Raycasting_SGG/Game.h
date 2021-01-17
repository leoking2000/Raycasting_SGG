#pragma once
#include "Camera.h"
#include "Level.h"
#include "Menu.h"

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
	void LoadLevel(int num);
private:
	//////////Game Functions/////////////////////////////

	void UpdatePlayScreen();
	void DrawPlayScreen();

	void ManageMenu(Menu& menu);
	
private:
	enum State
	{
		MAINMENU,
		LEVELSELECTOR,
		PLAYSCREEN,
	};
private:
	class Back : public Ifunctor
	{
	private:
		Game::State& state;

	public:
		Back(Game::State& state);
		void Do() override;
	};
private:
	//////////////Game variables/////////////////////////

	int canvaswidth = 1600;
	int canvasheight = 900;
	Level level;
	Camera camera;

	Menu main_menu;
	Menu level_selector;

	int levelNumber = 1;

	const float levelShowPeriod = 5000; // in milliseconds
	float timePassed = 0;
	bool showed = false;

	bool upArrowPress = false;
	bool downArrowPress = false;
	bool spaceEnder = false;

	Game::State state = Game::State::MAINMENU;
};
