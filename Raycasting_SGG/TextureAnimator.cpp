#include "TextureAnimator.h"
#include "graphics.h"

TextureAnimator::TextureAnimator(std::vector<std::string> textures, float period, bool loop = true)
	:
	Textures(textures),
	period(period),
	loop(loop)
{
}

void TextureAnimator::Tick()
{
	if (isOver) return;

	timePassed += graphics::getDeltaTime();

	if (period <= timePassed)
	{
		timePassed = 0;
		textureIndex++;

		if (textureIndex == Textures.size())
		{
			textureIndex = 0;
			isOver = !loop;
		}
	}
}

const std::string& TextureAnimator::GetTexture() const
{
	return Textures[textureIndex];
}

bool TextureAnimator::IsOver() const
{
	return isOver;
}

void TextureAnimator::reset()
{
	isOver = false;
}
