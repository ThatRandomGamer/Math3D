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

float Vector2::dot(const Vector2& a, const Vector2& b)
{
	return a.x * b.x + a.y * b.y;
}

float Vector2::magnitude(const Vector2& v2)
{
	return sqrt(v2.x * v2.x + v2.y * v2.y);
}

float Vector2::magSq(const Vector2& v2)
{
	return v2.x * v2.x + v2.y * v2.y;
}

const Vector2 Vector2::normalize(const Vector2& v2)
{
	float mag = Vector2::magnitude(v2);

	return Vector2(v2.x / mag, v2.y / mag);
}

const Vector2 Vector2::operator-() const
{
	return Vector2(-x, -y);
}

bool Vector2::operator==(const Vector2& v2)
{
	return x == v2.x && y == v2.y;
}

bool Vector2::operator!=(const Vector2& v2)
{
	return x != v2.x || y != v2.y;
}

const Vector2 Vector2::operator+(const Vector2& v2) const
{
	return Vector2(x + v2.x, y + v2.y);
}

const Vector2 Vector2::operator-(const Vector2& v2) const
{
	return Vector2(x - v2.x, y - v2.y);
}

const Vector2 Vector2::operator*(const Vector2& v2) const
{
	return Vector2(x * v2.x, y * v2.y);
}

const Vector2 Vector2::operator/(const Vector2& v2) const
{
	return Vector2(x / v2.x, y / v2.y);
}

const Vector2 Vector2::operator+(float n) const
{
	return Vector2(x + n, y + n);
}

const Vector2 Vector2::operator-(float n) const
{
	return Vector2(x - n, y - n);
}

const Vector2 Vector2::operator*(float n) const
{
	return Vector2(x * n, y * n);
}

const Vector2 Vector2::operator/(float n) const
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
	assert(i >= 0 && i <= 1);

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
