#pragma once
#include "Vector2.h"

template<typename T>
class Rectangle_t
{
public:
	Rectangle_t(T top, T left, T right, T bottom)
		:
		top(top),left(left),right(right),bottom(bottom)
	{
	}
	Rectangle_t(T centerX, T centerY, T width, T height)
		:
		top(centerY - height / T(2)), left(centerX - width / T(2)), right(centerX + width / T(2)), bottom(centerY + height / T(2))
	{
	}

	bool isCollidingWith(const Rectangle<T> other) const
	{
		return right > other.left && left < other.right
			&& bottom > other.top && top < other.bottom;
	}

	T GetWidth() const
	{
		return right - left;
	}
	T GetHeight() const
	{
		return bottom - top;
	}
	Vector2D_t<T> GetCenter() const
	{
		return Vector2D_t<T>(left + GetWidth() / T(2), top + GetHeight() / T(2));
	}



private:
	T top;
	T left;
	T right;
	T bottom;
};
