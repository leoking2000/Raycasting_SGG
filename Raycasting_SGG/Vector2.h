#pragma once


class Vector2
{
public:
	float x = 0.0f;
	float y = 0.0f;
public:
	Vector2() = default;
	Vector2(float in_x, float in_y);

	bool operator==(const Vector2& vec) const;

	Vector2 operator+(const Vector2& vec) const;
	Vector2 operator+(int num) const;
	Vector2& operator+=(const Vector2& vec);
	Vector2 operator-(const Vector2& vec) const;
	Vector2 operator-(int num) const;
	Vector2& operator-=(const Vector2& vec);
	Vector2 operator*(float scaler) const;
	Vector2& operator*=(float scaler);
	Vector2 operator/(float scaler) const;
	Vector2& operator/=(float scaler);

	float operator*(const Vector2& vec) const; // dot product

	void Rotate(float radians);
	float GetLengthSq() const;
	float GetLength() const;
	float GetDistanceSq(const Vector2& vec) const;
	float GetDistance(const Vector2& vec) const;
	Vector2& Normalize();
	Vector2  GetNormalized() const;



};

