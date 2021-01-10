#pragma once
#include <string>
#include <vector>

class TextureAnimator
{
public:
	TextureAnimator(std::vector<std::string> textures, float period, bool loop);

	void Tick(); // is called every frame.
	const std::string& GetTexture() const;

	bool IsOver() const;
	void reset();

private:
	std::vector<std::string> Textures;
	int textureIndex = 0;

	const bool loop;
	bool isOver = false;

	float period; // in milliseconds
	float timePassed = 0;
};

