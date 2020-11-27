#include "Vector2.h"
#include <cmath>

Vector2::Vector2(float in_x, float in_y)
{
	x = in_x;
	y = in_y;
}

bool Vector2::operator==(const Vector2& vec) const
{
	return x == vec.x && y == vec.y;
}

Vector2 Vector2::operator+(const Vector2& vec) const
{
	return Vector2(x + vec.x , y + vec.y);
}

Vector2 Vector2::operator+(int num) const
{
	return Vector2(x + num, y + num);
}

Vector2& Vector2::operator+=(const Vector2& vec)
{
	*this = *this + vec;
	return *this;
}

Vector2 Vector2::operator-(const Vector2& vec) const
{
	return Vector2(x - vec.x, y - vec.y);
}

Vector2 Vector2::operator-(int num) const
{
	return Vector2(x - num, y - num);
}

Vector2& Vector2::operator-=(const Vector2& vec)
{
	*this = *this - vec;
	return *this;
}

Vector2 Vector2::operator*(float scaler) const
{
	return Vector2(x * scaler , y * scaler);
}

Vector2& Vector2::operator*=(float scaler)
{
	*this = *this * scaler;
	return *this;
}

Vector2 Vector2::operator/(float scaler) const
{
	return Vector2(x / scaler, y / scaler);
}

Vector2& Vector2::operator/=(float scaler)
{
	*this = *this / scaler;
	return *this;
}

float Vector2::operator*(const Vector2& vec) const
{
	return x * vec.x + y * vec.y;
}

void Vector2::Rotate(float radians)
{
	x = x * std::cos(radians) - y * std::sin(radians);
	y = x * std::sin(radians) + y * std::cos(radians);
}

float Vector2::GetLengthSq() const
{
	return x * x + y * y;
}

float Vector2::GetLength() const
{
	return std::sqrt( GetLengthSq() );
}

float Vector2::GetDistanceSq(const Vector2& vec) const
{
	return (*this - vec).GetLengthSq();
}

float Vector2::GetDistance(const Vector2& vec) const
{
	return (*this - vec).GetLength();
}

Vector2& Vector2::Normalize()
{
	const float len = GetLength();
	if (len == 0.0f) return *this;

	*this = *this / len;

	return *this;
}

Vector2 Vector2::GetNormalized() const
{
	const float len = GetLength();
	if (len == 0.0f) return Vector2(x,y);

	return Vector2(x / len , y / len);
}

