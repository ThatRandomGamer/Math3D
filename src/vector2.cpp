#include "vector2.hpp"
#include <cassert>
#include <cmath>

Vector2::Vector2()
: x(0), y(0)
{
}

Vector2::Vector2(float x, float y)
: x(x), y(y)
{
}

Vector2::Vector2(const Vector2& v2)
: x(v2.x), y(v2.y)
{
}

float Vector2::dot(const Vector2& v2) const
{
	return x * v2.x + y * v2.y;
}

float Vector2::magnitude() const
{
	return sqrt(x * x + y * y);
}

float Vector2::magSq() const
{
	return x * x + y * y;
}

Vector2 Vector2::normalize() const
{
	float mag = magnitude();

	return Vector2(x / mag, y / mag);
}

Vector2 Vector2::operator-() const
{
	return Vector2(-x, -y);
}

bool Vector2::operator==(const Vector2& v2) const
{
	return x == v2.x && y == v2.y;
}

bool Vector2::operator!=(const Vector2& v2) const
{
	return x != v2.x || y != v2.y;
}

Vector2 Vector2::operator+(const Vector2& v2) const
{
	return Vector2(x + v2.x, y + v2.y);
}

Vector2 Vector2::operator-(const Vector2& v2) const
{
	return Vector2(x - v2.x, y - v2.y);
}

Vector2 Vector2::operator*(const Vector2& v2) const
{
	return Vector2(x * v2.x, y * v2.y);
}

Vector2 Vector2::operator/(const Vector2& v2) const
{
	return Vector2(x / v2.x, y / v2.y);
}

Vector2 Vector2::operator+(float n) const
{
	return Vector2(x + n, y + n);
}

Vector2 Vector2::operator-(float n) const
{
	return Vector2(x - n, y - n);
}

Vector2 Vector2::operator*(float n) const
{
	return Vector2(x * n, y * n);
}

Vector2 Vector2::operator/(float n) const
{
	return Vector2(x / n, y / n);
}

Vector2& Vector2::operator+=(const Vector2& v2)
{
	x += v2.x;
	y += v2.y;

	return *this;
}

Vector2& Vector2::operator-=(const Vector2& v2)
{
	x -= v2.x;
	y -= v2.y;

	return *this;
}

Vector2& Vector2::operator*=(const Vector2& v2)
{
	x *= v2.x;
	y *= v2.y;

	return *this;
}

Vector2& Vector2::operator/=(const Vector2& v2)
{
	x /= v2.x;
	y /= v2.y;

	return *this;
}

Vector2& Vector2::operator+=(float n)
{
	x += n;
	y += n;

	return *this;
}

Vector2& Vector2::operator-=(float n)
{
	x -= n;
	y -= n;

	return *this;
}

Vector2& Vector2::operator*=(float n)
{
	x *= n;
	y *= n;

	return *this;
}

Vector2& Vector2::operator/=(float n)
{
	x /= n;
	y /= n;

	return *this;
}

float Vector2::operator[](int i)
{
	switch (i)
	{
		case 0:
			return x;
		case 1:
			return y;
		default:
			return 0;
	}
}

const float Vector2::operator[](int i) const
{
	switch (i)
	{
		case 0:
			return x;
		case 1:
			return y;
		default:
			return 0;
	}
}
