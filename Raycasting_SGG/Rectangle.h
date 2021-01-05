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
	Rectangle_t(Vector2D_t<T> center, T width, T height)
		:
		top(center.y - height / T(2)), left(center.x - width / T(2)), right(center.x + width / T(2)), bottom(center.y + height / T(2))
	{
	}

	bool IntersectsWith(const Rectangle_t<T> other) const
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

	void SetCenter(const Vector2D_t<T> center)
	{
		const T width = GetWidth();
		const T height = GetWidth();

		top = center.y - height / T(2);
		left = center.x - width / T(2);
		right = center.x + width / T(2);
		bottom = center.y + height / T(2);
	}

private:
	T top;
	T left;
	T right;
	T bottom;
};

typedef Rectangle_t<float>  Rectangle;
typedef Rectangle_t<double> RectangleDouble;
typedef Rectangle_t<int>    RectangleInt;

