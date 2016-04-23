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

float Vector3::dot(const Vector3& a, const Vector3& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

const Vector3 Vector3::cross(const Vector3& a, const Vector3& b)
{
	float nx = a.y * b.z - a.z * b.y;
	float ny = a.z * b.x - a.x * b.z;
	float nz = a.x * b.y - a.y * b.x;

	return Vector3(nx, nz, nz);
}

float Vector3::magnitude(const Vector3& v3)
{
	return sqrt(v3.x * v3.x + v3.y * v3.y + v3.z * v3.z);
}

float Vector3::magSq(const Vector3& v3)
{
	return v3.x * v3.x + v3.y * v3.y + v3.z * v3.z;
}

const Vector3 Vector3::normalize(const Vector3& v3)
{
	float mag = Vector3::magnitude(v3);
	
	return Vector3(v3.x / mag, v3.y / mag, v3.z / mag);
}

const Vector3 Vector3::rotateBy(const Quaternion& rot) const
{
	Quaternion conj = Quaternion::conjugate(rot);
	Quaternion w = rot * (*this) * conj;

	return Vector3(w.x, w.y, w.z);
}

const Vector3 Vector3::rotateBy(const Vector3& axis, float angle) const
{
	float sinA = sin(-angle);
	float cosA = cos(-angle);

	return Vector3::cross(*this, axis * sinA + (*this) * cosA + axis
		* Vector3::dot(*this, axis * (1 - cosA)));
}

bool Vector3::operator==(const Vector3& v3)
{
	return x == v3.x && y == v3.y && z == v3.z;
}

bool Vector3::operator!=(const Vector3& v3)
{
	return x != v3.x || y != v3.y || z != v3.z;
}

const Vector3 Vector3::operator-() const
{
	return Vector3(-x, -y, -z);
}

const Vector3 Vector3::operator+(const Vector3& v3) const
{
	return Vector3(x + v3.x, y + v3.y, z + v3.z);
}

const Vector3 Vector3::operator-(const Vector3& v3) const
{
	return Vector3(x - v3.x, y - v3.y, z - v3.z);
}

const Vector3 Vector3::operator*(const Vector3& v3) const
{
	return Vector3(x * v3.x, y * v3.y, z * v3.z);
}

const Vector3 Vector3::operator/(const Vector3& v3) const
{
	return Vector3(x / v3.x, y / v3.y, z / v3.z);
}

const Vector3 Vector3::operator+(float n) const
{
	return Vector3(x + n, y + n, z + n);
}

const Vector3 Vector3::operator-(float n) const
{
	return Vector3(x - n, y - n, z - n);
}

const Vector3 Vector3::operator*(float n) const
{
	return Vector3(x * n, y * n, z * n);
}

const Vector3 Vector3::operator/(float n) const
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
	assert(i >= 0 && i <= 2);

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
