#pragma once
#include "graphics.h"

class Camera
{
public:
	Camera(int width);
	~Camera();
	Camera(const Camera& g) = delete;
	Camera& operator=(const Camera& g) = delete;

	void Render();
	void ResizeBuffer();
private:
	// 1D buffer, stores the distance from player to wall from every ray cast in a pixel column.
	float* p_zBuffer = nullptr; 
	graphics::Brush br;
	graphics::Brush sky;
};

