#pragma once
#include "Vector2.h"

template<typename T>
class Circle_t
{
public:
	Circle_t(Vector2D_t<T> center, T radius)
		:
		position(center),
		radius(radius)
	{
	}

	bool IntersectsWith(const Circle_t<T> other) const
	{
		return (radius + other.radius) > position.GetDistance(other.position);
	}
	bool contains(const Vector2D_t<T> point) const
	{
		return position.GetDistance(point) < radius;
	}
	T GetRadious() const
	{
		return radius;
	}
	Vector2D_t<T> GetCenter() const
	{
		return position;
	}

	void ResolveCollisionStatic(const Circle_t<T>& other)
	{
		const Vector2 deltaCenter = position - other.position;
		const float dis = deltaCenter.GetLength();

		const float overlap = dis - radius - other.radius;

		position -= deltaCenter.GetNormalized() * overlap;
	}

	void ResolveCollisionDynamic(Circle_t<T>& other)
	{
		const Vector2 deltaCenter = position - other.position;
		const float dis = deltaCenter.GetLength();

		const float overlap = dis - radius - other.radius;

		position -= deltaCenter.GetNormalized() * (overlap * 0.5f);
		other.position += deltaCenter.GetNormalized() * (overlap * 0.5f);
	}

	void SetCenter(const Vector2D_t<T> center)
	{
		position = center;
	}

private:
	T radius;
	Vector2D_t<T> position; // the center.
};

typedef Circle_t<float>  Circle;
typedef Circle_t<double> CircleDouble;
typedef Circle_t<int>    CircleInt;
