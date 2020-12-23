#pragma once
#include "graphics.h"
#include "Level.h"

class Camera
{
public:
	Camera(const Level* pLevel, int width, int height);
	~Camera();

	void setLevel(const Level* pLevel_in);

	void Render();

private:
	const Level* pLevel;

	const int width;
	const int height;

	float* p_zBuffer = nullptr;

	graphics::Brush br;
	graphics::Brush sky;
};

