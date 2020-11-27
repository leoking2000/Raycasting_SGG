#pragma once
#include "graphics.h"
#include "Scene.h"

class Camera
{
public:
	Camera(const Scene* pScene);

	void setScene(const Scene* pScene);

	void RenderSceneAt(int x, int y, int width, int height) const;

private:
	const Scene* pScene;

};

