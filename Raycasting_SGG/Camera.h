#pragma once
#include "graphics.h"
#include "Scene.h"

class Camera
{
public:
	Camera(const Scene* pScene, int width, int height);
	~Camera();

	void setScene(const Scene* pScene);

	void RenderScene();

private:
	const Scene* pScene;

	const int width;
	const int height;

	float* p_zBuffer = nullptr;

	graphics::Brush br;
	graphics::Brush sky;
};

