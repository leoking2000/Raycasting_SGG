#include "Game.h"
#include <xmemory>

void Update(float dt)
{
	Game* game = reinterpret_cast<Game*>(graphics::getUserData());

	game->Update();
}

void Draw()
{
	Game* game = reinterpret_cast<Game*>(graphics::getUserData());

	game->Draw();
}

void resize(int new_w, int new_h)
{
	Game* game = reinterpret_cast<Game*>(graphics::getUserData());

	game->ResizeCanvas(new_w, new_h);
}

int main()
{
	// code to detect memory leaks
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

    graphics::createWindow(1600, 900, "Game");
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
	graphics::setCanvasSize((float)1600, (float)900);

	/*
	*  we create the game with new because 
	*  we want to delete before we check for memory leaks
	*/

	Game* game = new Game();

	graphics::setUserData(game);
	graphics::setDrawFunction(Draw);
	graphics::setUpdateFunction(Update);
	graphics::setResizeFunction(resize);

	graphics::startMessageLoop();

	graphics::destroyWindow();

	delete game;

	// code to detect memory leaks
	_CrtDumpMemoryLeaks();
    return 0;
}
