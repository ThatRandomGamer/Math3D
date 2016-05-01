#include "quaternion.hpp"
#include <cmath>

#define EPSILON	1e3f

Quaternion::Quaternion(float x, float y, float z, float w)
: x(x), y(y), z(z), w(w)
{
}

Quaternion::Quaternion(const Quaternion& q)
: x(q.x), y(q.y), z(q.z), w(q.w)
{
}

Quaternion Quaternion::fromAxisAngle(float x, float y, float z, float angle)
{
	float sinHalfA = sin(angle / 2);

	return Quaternion(x * sinHalfA, y * sinHalfA, z * sinHalfA, cos(angle / 2));
}

Quaternion Quaternion::fromAxisAngle(const Vector3& axis, float angle)
{
	float sinHalfA = sin(angle / 2);

	return Quaternion(axis.x * sinHalfA, axis.y * sinHalfA, axis.z * sinHalfA, cos(angle / 2));
}

Quaternion Quaternion::fromAxisAngle(const Vector3& axis)
{
	Vector3 normAxis = axis.normalize();
	float angle = axis.magnitude();
	float sinHalfA = sin(angle / 2);

	return Quaternion(normAxis.x * sinHalfA, normAxis.y * sinHalfA, normAxis.z * sinHalfA, cos(angle / 2));
}

Quaternion Quaternion::fromEulerAngles(float x, float y, float z)
{
	float sin1 = sin(x / 2);
	float cos1 = cos(x / 2);

	float sin2 = sin(z / 2);
	float cos2 = cos(z / 2);

	float sin3 = sin(y / 2);
	float cos3 = cos(y / 2);

	float s1s2 = sin1 * sin2;
	float c1c2 = cos1 * cos2;

	return Quaternion(sin1 * cos2 * cos3 + cos1 * sin2 * sin3,
		c1c2 * sin3 + s1s2 * cos3,
		cos1 * sin2 * cos3 - sin1 * cos2 * sin3,
		c1c2 * cos3 - s1s2 * sin3);
}

Quaternion Quaternion::fromEulerAngles(const Vector3& angles)
{
	float sin1 = sin(angles.x / 2);
	float cos1 = cos(angles.x / 2);

	float sin2 = sin(angles.z / 2);
	float cos2 = cos(angles.z / 2);

	float sin3 = sin(angles.y / 2);
	float cos3 = cos(angles.y / 2);

	float s1s2 = sin1 * sin2;
	float c1c2 = cos1 * cos2;

	return Quaternion(sin1 * cos2 * cos3 + cos1 * sin2 * sin3,
		c1c2 * sin3 + s1s2 * cos3,
		cos1 * sin2 * cos3 - sin1 * cos2 * sin3,
		c1c2 * cos3 - s1s2 * sin3);
}

Quaternion Quaternion::fromMatrix(const Matrix4x4& m4)
{
	float x, y, z, w;
	float trace = m4[0][0] + m4[1][1] + m4[2][2];

	if (trace > 0)
	{
		float s = 0.5f / sqrt(trace + 1.0f);
		w = 0.25f / s;
		x = (m4[1][2] - m4[2][1]) * s;
		y = (m4[2][0] - m4[0][2]) * s;
		z = (m4[0][1] - m4[1][0]) * s;
	}
	else
	{
		if (m4[0][0] > m4[1][1] && m4[0][0] > m4[2][2])
		{
			float s = 2.0f * sqrt(1.0f + m4[0][0] - m4[1][1] - m4[2][2]);
			w = (m4[1][2] - m4[2][1]) / s;
			x = 0.25f * s;
			y = (m4[1][0] + m4[0][1]) / s;
			z = (m4[2][0] + m4[0][2]) / s;
		}
		else if (m4[1][1] > m4[2][2])
		{
			float s = 2.0f * sqrt(1.0f + m4[1][1] - m4[0][0] - m4[2][2]);
			w = (m4[2][0] - m4[0][2]) / s;
			x = (m4[1][0] + m4[0][1]) / s;
			y = 0.25f * s;
			z = (m4[2][1] + m4[1][2]) / s;
		}
		else
		{
			float s = 2.0f * sqrt(1.0f + m4[2][2] - m4[0][0] - m4[1][1]);
			w = (m4[0][1] - m4[1][0]) / s;
			x = (m4[2][0] + m4[0][2]) / s;
			y = (m4[1][2] + m4[2][1]) / s;
			z = 0.25f * s;
		}
	}

	float mag = sqrt(x * x +  y * y + z * z + w * w);

	if (mag != 0)
	{
		x /= mag;
		y /= mag;
		z /= mag;
		w /= mag;
	}

	return Quaternion(x, y, z, w);
}

float Quaternion::magnitude() const
{
	return sqrt(x * x + y * y + z * z + w * w);
}

float Quaternion::magSq() const
{
	return x * x + y * y + z * z + w * w;
}

Quaternion Quaternion::normalize() const
{
	float mag = magnitude();

	return Quaternion(x / mag, y / mag, z / mag, w / mag);
}

Quaternion Quaternion::conjugate() const
{
	return Quaternion(-x, -y, -z, w);
}

float Quaternion::dot(const Quaternion& q) const
{
	return x * q.x + y * q.y + z * q.z + w * q.w;
}

Quaternion Quaternion::nlerp(const Quaternion& to, float inc, bool shortest) const
{
	Quaternion correctedTo = to;

	if (shortest && dot(to) < 0)
	{
		correctedTo = -to;
	}

	return ((*this) + (correctedTo - (*this)) * inc).normalize();
}

Quaternion Quaternion::slerp(const Quaternion& to, float inc, bool shortest) const
{
	float cs = dot(to);
	Quaternion correctedTo = to;

	if (shortest && cs < 0)
	{
		cs = -cs;
		correctedTo = -to;
	}

	if (std::abs(cs) >= 1 - EPSILON)
	{
		return nlerp(correctedTo, inc, false);
	}

	float sn = sqrt(1.0f - cs * cs);
	float angle = atan2(sn, cs);
	float invSin = 1.0f / sn;

	float srcFactor = sin((1.0f - inc) * angle) * invSin;
	float destFactor = sin(inc * angle) * invSin;

	return (*this) * srcFactor + correctedTo * destFactor;
}

Quaternion Quaternion::rotateBy(const Quaternion& by) const
{
	return (by * (*this)).normalize();
}

bool Quaternion::operator==(const Quaternion& q) const
{
	return x == q.x && y == q.y && z == q.z && w == q.w;
}

bool Quaternion::operator!=(const Quaternion& q) const
{
	return x != q.x || y != q.y || z != q.z || w != q.w;
}

Quaternion Quaternion::operator-() const
{
	return Quaternion(-x, -y, -z, -w);
}

Quaternion Quaternion::operator+(const Quaternion& q) const
{
	return Quaternion(x + q.x, y + q.y, z + q.z, w + q.w);
}

Quaternion Quaternion::operator-(const Quaternion& q) const
{
	return Quaternion(x - q.x, y - q.y, z - q.z, w - q.w);
}

Quaternion Quaternion::operator*(const Quaternion& q) const
{
	float nx = x * q.w + w * q.x + y * q.z - z * q.y;
	float ny = y * q.w + w * q.y + z * q.x - x * q.z;
	float nz = z * q.w + w * q.z + x * q.y - y * q.x;
	float nw = w * q.w - x * q.x - y * q.y - z * q.z;

	return Quaternion(nx, ny, nz, nw);
}

Quaternion Quaternion::operator*(const Vector3& v3) const
{
	float nx = w * v3.x + y * v3.z - z * v3.y;
	float ny = w * v3.y + z * v3.x - x * v3.z;
	float nz = w * v3.z + x * v3.y - y * v3.x;
	float nw = -x * v3.x - y * v3.y - z * v3.z;

	return Quaternion(nx, ny, nz, nw);
}

Quaternion Quaternion::operator*(float n) const
{
	return Quaternion(x * n, y * n, z * n, w * n);
}

Vector3 Quaternion::forward() const
{
	return Vector3(0, 0, 1).rotateBy(*this);
}

Vector3 Quaternion::back() const
{
	return Vector3(0, 0, -1).rotateBy(*this);
}

Vector3 Quaternion::left() const
{
	return Vector3(-1, 0, 0).rotateBy(*this);
}

Vector3 Quaternion::right() const
{
	return Vector3(1, 0, 0).rotateBy(*this);
}

Vector3 Quaternion::up() const
{
	return Vector3(0, 1, 0).rotateBy(*this);
}

Vector3 Quaternion::down() const
{
	return Vector3(0, -1, 0).rotateBy(*this);
}

float Quaternion::operator[](int i)
{
	switch (i)
	{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		default:
			return 0;
	}
}

const float Quaternion::operator[](int i) const
{
	switch (i)
	{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		default:
			return 0;
	}
}
