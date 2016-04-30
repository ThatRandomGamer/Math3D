#include "vector3.hpp"
#include <cassert>
#include <cmath>

#include "quaternion.hpp"

Vector3::Vector3()
: x(0), y(0), z(0)
{
}

Vector3::Vector3(float x, float y, float z)
: x(x), y(y), z(z)
{
}

Vector3::Vector3(const Vector3& v3)
: x(v3.x), y(v3.y), z(v3.z)
{
}

float Vector3::dot(const Vector3& v3) const
{
	return x * v3.x + y * v3.y + z * v3.z;
}

Vector3 Vector3::cross(const Vector3& v3) const
{
	float nx = y * v3.z - z * v3.y;
	float ny = z * v3.x - x * v3.z;
	float nz = x * v3.y - y * v3.x;

	return Vector3(nx, ny, nz);
}

float Vector3::magnitude() const
{
	return sqrt(x * x + y * y + z * z);
}

float Vector3::magSq() const
{
	return x * x + y * y + z * z;
}

Vector3 Vector3::normalize() const
{
	float mag = magnitude();
	
	return Vector3(x / mag, y / mag, z / mag);
}

Vector3 Vector3::rotateBy(const Quaternion& rot) const
{
	Quaternion conj = rot.conjugate();
	Quaternion w = rot * (*this) * conj;

	return Vector3(w.x, w.y, w.z);
}

Vector3 Vector3::rotateBy(const Vector3& axis, float angle) const
{
	float sinA = sin(-angle);
	float cosA = cos(-angle);

	return cross(axis * sinA + (*this) * cosA + axis
		* dot(axis * (1 - cosA)));
}

bool Vector3::operator==(const Vector3& v3) const
{
	return x == v3.x && y == v3.y && z == v3.z;
}

bool Vector3::operator!=(const Vector3& v3) const
{
	return x != v3.x || y != v3.y || z != v3.z;
}

Vector3 Vector3::operator-() const
{
	return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator+(const Vector3& v3) const
{
	return Vector3(x + v3.x, y + v3.y, z + v3.z);
}

Vector3 Vector3::operator-(const Vector3& v3) const
{
	return Vector3(x - v3.x, y - v3.y, z - v3.z);
}

Vector3 Vector3::operator*(const Vector3& v3) const
{
	return Vector3(x * v3.x, y * v3.y, z * v3.z);
}

Vector3 Vector3::operator/(const Vector3& v3) const
{
	return Vector3(x / v3.x, y / v3.y, z / v3.z);
}

Vector3 Vector3::operator+(float n) const
{
	return Vector3(x + n, y + n, z + n);
}

Vector3 Vector3::operator-(float n) const
{
	return Vector3(x - n, y - n, z - n);
}

Vector3 Vector3::operator*(float n) const
{
	return Vector3(x * n, y * n, z * n);
}

Vector3 Vector3::operator/(float n) const
{
	return Vector3(x / n, y / n, z / n);
}

Vector3& Vector3::operator+=(const Vector3& v3)
{
	x += v3.x;
	y += v3.y;
	z += v3.z;

	return *this;
}

Vector3& Vector3::operator-=(const Vector3& v3)
{
	x -= v3.x;
	y -= v3.y;
	z -= v3.z;

	return *this;
}

Vector3& Vector3::operator*=(const Vector3& v3)
{
	x *= v3.x;
	y *= v3.y;
	z *= v3.z;

	return *this;
}

Vector3& Vector3::operator/=(const Vector3& v3)
{
	x /= v3.x;
	y /= v3.y;
	z /= v3.z;

	return *this;
}

Vector3& Vector3::operator+=(float n)
{
	x += n;
	y += n;
	z += n;

	return *this;
}

Vector3& Vector3::operator-=(float n)
{
	x -= n;
	y -= n;
	z -= n;

	return *this;
}

Vector3& Vector3::operator*=(float n)
{
	x *= n;
	y *= n;
	z *= n;

	return *this;
}

Vector3& Vector3::operator/=(float n)
{
	x /= n;
	y /= n;
	z /= n;

	return *this;
}

float Vector3::operator[](int i)
{
	switch (i)
	{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		default:
			return 0;
	}
}

const float Vector3::operator[](int i) const
{
	switch (i)
	{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		default:
			return 0;
	}
}
