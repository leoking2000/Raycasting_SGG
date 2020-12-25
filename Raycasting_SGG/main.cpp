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

int main()
{
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

    graphics::createWindow(CanvasWidth, CanvasHeight, "Game");
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_WINDOW);
	graphics::setCanvasSize((float)CanvasWidth, (float)CanvasHeight);

	Game* game = new Game();

	graphics::setUserData(game);
	graphics::setDrawFunction(Draw);
	graphics::setUpdateFunction(Update);

	graphics::startMessageLoop();

	graphics::destroyWindow();

	delete game;

	_CrtDumpMemoryLeaks();
    return 0;
}
