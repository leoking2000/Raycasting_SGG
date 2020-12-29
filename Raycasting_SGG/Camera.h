#pragma once
#include "graphics.h"
#include "Level.h"

class Camera
{
public:
	Camera(int width);
	~Camera();
	void Render();
	void ResizeBuffer();
private:
	float* p_zBuffer = nullptr;

	graphics::Brush br;
	graphics::Brush sky;
};

