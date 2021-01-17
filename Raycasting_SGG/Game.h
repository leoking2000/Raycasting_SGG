#pragma once
#include "Camera.h"
#include "Level.h"
#include "Menu.h"

// a class to hold the game state and logic
class Game
{
public:
	Game();
	~Game();
	Game(const Game& g) = delete;
	Game& operator=(const Game& g) = delete;

	int CanvasWidth() const;
	int CanvasHeight() const;
	Level& GetLevel();

	void Update();
	void Draw();
	void ResizeCanvas(int w, int h);
private:
	void LoadLevel(int num);

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

	class LevelLoader : public Ifunctor
	{
	private:
		const int levelNum;
		Game& game;
	public:
		LevelLoader(int levelNum, Game& game);

		void Do() override;
	};
private:
	int canvaswidth = 1600;
	int canvasheight = 900;
	Level level;
	Camera camera;

	Menu main_menu;
	Menu level_selector;

	int levelNumber = 1;

	// for the level pop up at hte beggining of a level
	const float levelShowPeriod = 5000; // in milliseconds
	float timePassed = 0;
	bool showed = false;

	// for Menu managment
	bool upArrowPress = false;
	bool downArrowPress = false;
	bool spacePress = false;

	Game::State state = Game::State::MAINMENU;
};
