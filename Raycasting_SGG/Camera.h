#pragma once
#include "graphics.h"
#include "Scene.h"

class Camera
{
public:
	Camera(const Scene* pScene, int width, int height);

	void setScene(const Scene* pScene);

	void RenderSceneAt(int x, int y);

private:
	const Scene* pScene;
	const int width;
	const int height;

	graphics::Brush br;
	graphics::Brush sky;

};

