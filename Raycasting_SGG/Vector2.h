#pragma once
#include <cmath>

template<typename T>
class Vector2D_t
{
public:
	T x;
	T y;
public:
	Vector2D_t() = default;
	Vector2D_t(T in_x, T in_y);

	inline bool operator==(const Vector2D_t<T>& vec) const;
	inline bool operator!=(const Vector2D_t<T>& vec) const;

	inline Vector2D_t<T> operator+(const Vector2D_t<T>& vec) const;
	inline Vector2D_t<T>& operator+=(const Vector2D_t<T>& vec);
	inline Vector2D_t<T> operator+(T scaler) const;
	inline Vector2D_t<T>& operator+=(T scaler);

	inline Vector2D_t<T> operator-() const;
	inline Vector2D_t<T> operator-(const Vector2D_t<T>& vec) const;
	inline Vector2D_t<T> operator-(T scaler) const;
	inline Vector2D_t<T>& operator-=(const Vector2D_t<T>& vec);
	inline Vector2D_t<T>& operator-=(T scaler);

	inline Vector2D_t<T> operator/(T scaler) const;
	inline Vector2D_t<T>& operator/=(T scaler);

	inline float operator*(const Vector2D_t<T>& vec) const; // dot product
	inline Vector2D_t<T> operator*(T scaler) const;
	inline Vector2D_t<T>& operator*=(T scaler);


	void Rotate(double radians);
	T GetLengthSq() const;
	T GetLength() const;
	T GetDistanceSq(const Vector2D_t<T>& vec) const;
	T GetDistance(const Vector2D_t<T>& vec) const;
	Vector2D_t  GetNormalized() const;
	Vector2D_t& Normalize();

};

template<typename T>
Vector2D_t<T>::Vector2D_t(T x, T y) : x(x), y(y) {}


////////////////// == != ////////////////////////////
template<typename T>
inline bool Vector2D_t<T>::operator==(const Vector2D_t<T>& vec) const
{
	return x == vec.x && y == vec.y;
}

template<typename T>
inline bool Vector2D_t<T>::operator!=(const Vector2D_t<T>& vec) const
{
	return x != vec.x || y != vec.y;
}

//////////////////// + += ///////////////////////
template<typename T>
inline Vector2D_t<T> Vector2D_t<T>::operator+(const Vector2D_t<T>& vec) const
{
	return Vector2D_t<T>(x + vec.x, y + vec.y);
}

template<typename T>
inline Vector2D_t<T>& Vector2D_t<T>::operator+=(const Vector2D_t<T>& vec)
{
	*this = *this + vec;
	return *this;
}

template<typename T>
inline Vector2D_t<T> Vector2D_t<T>::operator+(T scaler) const
{
	return Vector2D_t<T>(x + scaler, y + scaler);
}

template<typename T>
inline Vector2D_t<T> operator+(T scaler, const Vector2D_t<T>& vec)
{
	return Vector2D_t<T>(vec.x + scaler, vec.y + scaler);
}

template<typename T>
inline Vector2D_t<T>& Vector2D_t<T>::operator+=(T scaler)
{
	x += scaler;
	y += scaler;
	return *this;
}

//////////////// - -= /////////////////////////

template<typename T>
inline Vector2D_t<T> Vector2D_t<T>::operator-() const
{
	return Vector2D_t<T>(-x,-y);
}

template<typename T>
inline Vector2D_t<T> Vector2D_t<T>::operator-(const Vector2D_t<T>& vec) const
{
	return Vector2D_t<T>(x - vec.x, y - vec.y);
}

template<typename T>
inline Vector2D_t<T> Vector2D_t<T>::operator-(T scaler) const
{
	return Vector2D_t<T>(x - scaler, y - scaler);
}

template<typename T>
inline Vector2D_t<T> operator-(T scaler, const Vector2D_t<T>& vec)
{
	return Vector2D_t<T>(vec.x - scaler, vec.y - scaler);
}

template<typename T>
inline Vector2D_t<T>& Vector2D_t<T>::operator-=(const Vector2D_t<T>& vec)
{
	*this = *this - vec;
	return *this;
}

template<typename T>
inline Vector2D_t<T>& Vector2D_t<T>::operator-=(T scaler)
{
	x -= scaler;
	y -= scaler;
	return *this;
}

/////////////// / /= //////////////////////////////

template<typename T>
inline Vector2D_t<T> Vector2D_t<T>::operator/(T scaler) const
{
	return Vector2D_t<T>(x / scaler, y / scaler);
}

template<typename T>
inline Vector2D_t<T>& Vector2D_t<T>::operator/=(T scaler)
{
	x /= scaler;
	y /= scaler;
	return *this;
}

/////////////////// * //////////////////////////////

template<typename T>
inline float Vector2D_t<T>::operator*(const Vector2D_t<T>& vec) const
{
	return x * vec.x + y * vec.y;
}

template<typename T>
inline Vector2D_t<T> Vector2D_t<T>::operator*(T scaler) const
{
	return Vector2D_t(x * scaler, y * scaler);
}

template<typename T>
inline Vector2D_t<T> operator*(T scaler, const Vector2D_t<T>& vec)
{
	return Vector2D_t<T>(vec.x * scaler, vec.y * scaler);
}

template<typename T>
inline Vector2D_t<T>& Vector2D_t<T>::operator*=(T scaler)
{
	x *= scaler;
	y *= scaler;
	return *this;
}

/////////////////////////////////////////////////

template<typename T>
inline void Vector2D_t<T>::Rotate(double radians)
{
	x = T(x * std::cos(radians) - y * std::sin(radians));
	y = T(x * std::sin(radians) + y * std::cos(radians));
}

template<typename T>
T Vector2D_t<T>::GetLengthSq() const
{
	return x * x + y * y;
}

template<typename T>
T Vector2D_t<T>::GetLength() const
{
	return T(std::sqrt(GetLengthSq()));
}

template<typename T>
T Vector2D_t<T>::GetDistanceSq(const Vector2D_t<T>& vec) const
{
	return (*this - vec).GetLengthSq();
}

template<typename T>
inline T Vector2D_t<T>::GetDistance(const Vector2D_t<T>& vec) const
{
	return (*this - vec).GetLength();
}

template<typename T>
Vector2D_t<T> Vector2D_t<T>::GetNormalized() const
{
	const float len = GetLength();
	if ((double)len == 0.0) return Vector2D_t(*this);

	return Vector2D_t<T>(T(x / len), T(y / len));
}

template<typename T>
Vector2D_t<T>& Vector2D_t<T>::Normalize()
{
	const T len = GetLength();
	if ((double)len == 0.0) return *this;

	*this = *this / len;

	return *this;
}

typedef Vector2D_t<float>  Vector2;
typedef Vector2D_t<double> Vector2double;
typedef Vector2D_t<int>    Vector2int;
