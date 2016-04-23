#include "matrix4x4.hpp"
#include <cmath>
#include <cstring> //memset, memcpy

Matrix4x4::Matrix4x4()
{
	memset(&matrix, 0, 16 * sizeof(float));
}

Matrix4x4::Matrix4x4(const Matrix4x4& m4)
{
	memcpy(&matrix, &(m4.matrix), 16 * sizeof(float));
}	

float Matrix4x4::determinant(const Matrix4x4& m4)
{
	return -m4[0][2] * m4[1][1] * m4[2][0] + m4[0][1] * m4[1][2] * m4[2][0]
		+ m4[0][2] * m4[1][0] * m4[2][1] - m4[0][0] * m4[1][2] * m4[2][1]
		- m4[0][1] * m4[1][0] * m4[2][2] + m4[0][0] * m4[1][1]* m4[2][2];
}

const Matrix4x4 Matrix4x4::inverse(const Matrix4x4& m4)
{
	float det = Matrix4x4::determinant(m4);
	float k = 1.0f / det;

	Matrix4x4 out;

	out[0][0] = (m4[1][1] * m4[2][2] - m4[2][1] * m4[1][2]) * k;
	out[0][1] = (m4[2][1] * m4[0][2] - m4[0][1] * m4[2][2]) * k;
	out[0][2] = (m4[0][1] * m4[1][2] - m4[1][1] * m4[0][2]) * k;
	out[1][0] = (m4[1][2] * m4[2][0] - m4[2][2] * m4[1][0]) * k;
	out[1][1] = (m4[2][2] * m4[0][0] - m4[0][2] * m4[2][0]) * k;
	out[1][2] = (m4[0][2] * m4[1][0] - m4[1][2] * m4[0][0]) * k;
	out[2][0] = (m4[1][0] * m4[2][1] - m4[2][0] * m4[1][1]) * k;
	out[2][1] = (m4[2][0] * m4[0][1] - m4[0][0] * m4[2][1]) * k;
	out[2][2] = (m4[0][0] * m4[1][1] - m4[1][0] * m4[0][1]) * k;

	out[0][3] = -(out[0][0] * m4[0][3] + out[0][1] * m4[1][3] + out[0][2] * m4[2][3]);
	out[1][3] = -(out[1][0] * m4[0][3] + out[1][1] * m4[1][3] + out[1][2] * m4[2][3]);
	out[2][3] = -(out[2][0] * m4[0][3] + out[2][1] * m4[1][3] + out[2][2] * m4[2][3]);

	out[3][0] = m4[3][0];
	out[3][1] = m4[3][1];
	out[3][2] = m4[3][2];
	out[3][3] = m4[3][3];

	return out;
}

const Matrix4x4 Matrix4x4::transpose(const Matrix4x4& m4)
{
	Matrix4x4 out;

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			out[y][x] = m4[x][y];
		}
	}

	return out;
}

const Matrix4x4 Matrix4x4::identity()
{
	Matrix4x4 out;

	out[0][0] = 1;
	out[1][1] = 1;
	out[2][2] = 1;
	out[3][3] = 1;

	return out;
}

const Matrix4x4 Matrix4x4::position(float x, float y, float z)
{
	Matrix4x4 out;

	out[0][3] = x;
	out[1][3] = y;
	out[2][3] = z;
	out[3][3] = 1;

	return out;
}

const Matrix4x4 Matrix4x4::position(const Vector3& pos)
{
	Matrix4x4 out;

	out[0][3] = pos.x;
	out[1][3] = pos.y;
	out[2][3] = pos.z;
	out[3][3] = 1;

	return out;
}

const Matrix4x4 Matrix4x4::scale(float x, float y, float z)
{
	Matrix4x4 out;

	out[0][0] = x;
	out[1][1] = y;
	out[2][2] = z;
	out[3][3] = 1;
	
	return out;
}

const Matrix4x4 Matrix4x4::scale(const Vector3& scale)
{
	Matrix4x4 out;

	out[0][0] = scale.x;
	out[1][1] = scale.y;
	out[2][2] = scale.z;
	out[3][3] = 1;

	return out;
}

const Matrix4x4 Matrix4x4::rotation(float x, float y, float z)
{
	Matrix4x4 rx, ry, rz;

	float sinX = sin(x);
	float cosX = cos(x);

	rx[0][0] = 1;
	rx[1][1] = cosX;
	rx[2][1] = sinX;
	rx[1][2] = -sinX;
	rx[2][2] = cosX;
	rx[3][3] = 1;

	float sinY = sin(y);
	float cosY = cos(y);

	ry[0][0] = cosY;
	ry[1][1] = 1;
	ry[2][0] = -sinY;
	ry[0][2] = sinY;
	ry[2][2] = cosY;
	ry[3][3] = 1;

	float sinZ = sin(z);
	float cosZ = cos(z);

	rz[0][0] = cosZ;
	rz[1][0] = sinZ;
	rz[0][1] = -sinZ;
	rz[1][1] = cosZ;
	rz[2][2] = 1;
	rz[3][3] = 1;

	return rz * (ry * rx);
}

const Matrix4x4 Matrix4x4::rotation(const Vector3& rot)
{
	float x = rot.x;
	float y = rot.y;
	float z = rot.z;

	Matrix4x4 rx, ry, rz;

	float sinX = sin(x);
	float cosX = cos(x);

	rx[0][0] = 1;
	rx[1][1] = cosX;
	rx[2][1] = sinX;
	rx[1][2] = -sinX;
	rx[2][2] = cosX;
	rx[3][3] = 1;

	float sinY = sin(y);
	float cosY = cos(y);

	ry[0][0] = cosY;
	ry[1][1] = 1;
	ry[2][0] = sinY;
	ry[0][2] = -sinY;
	ry[2][2] = cosY;
	ry[3][3] = 1;

	float sinZ = sin(z);
	float cosZ = cos(z);

	rz[0][0] = cosZ;
	rz[1][0] = sinZ;
	rz[0][1] = -sinZ;
	rz[1][1] = cosZ;
	rz[2][2] = 1;
	rz[3][3] = 1;

	return rz * (ry * rx);
}

const Matrix4x4 Matrix4x4::rotation(float x, float y, float z, float w)
{
	Matrix4x4 out;

	out[0][0] = 1.0f - 2.0f * (y * y + z * z);
	out[0][1] = 2.0f * (x * y - w * z);
	out[0][2] = 2.0f * (x * z + w * y);

	out[1][0] = 2.0f * (x * y + w * z);
	out[1][1] = 1.0f - 2.0f * (x * x + z * z);
	out[1][2] = 2.0f * (y * z - w * x);

	out[2][0] = 2.0f * (x * z - w * y);
	out[2][1] = 2.0f * (y * z + w * x);
	out[2][2] = 1.0f - 2.0f * (x * x + y * y);

	out[3][3] = 1;

	return out;
}

const Matrix4x4 Matrix4x4::rotation(const Quaternion& rot)
{
	Matrix4x4 out;

	out[0][0] = 1.0f - 2.0f * (rot.y * rot.y + rot.z * rot.z);
	out[0][1] = 2.0f * (rot.x * rot.y - rot.w * rot.z);
	out[0][2] = 2.0f * (rot.x * rot.z + rot.w * rot.y);

	out[1][0] = 2.0f * (rot.x * rot.y + rot.w * rot.z);
	out[1][1] = 1.0f - 2.0f * (rot.x * rot.x + rot.z * rot.z);
	out[1][2] = 2.0f * (rot.y * rot.z - rot.w * rot.x);

	out[2][0] = 2.0f * (rot.x * rot.z - rot.w * rot.y);
	out[2][1] = 2.0f * (rot.y * rot.z + rot.w * rot.x);
	out[2][2] = 1.0f - 2.0f * (rot.x * rot.x + rot.y * rot.y);

	out[3][3] = 1;

	return out;
}

const Matrix4x4 Matrix4x4::fromAxisAngle(float x, float y, float z, float angle)
{
	Matrix4x4 out;

	float sinA = sin(angle);
	float cosA = cos(angle);
	float sCosA = 1 - cosA;

	out[0][0] = cosA + x * x * sCosA;
	out[0][1] = x * y * sCosA - z * sinA;
	out[0][2] = x * z * sCosA + y * sinA;

	out[1][0] = y * x * sCosA + z * sinA;
	out[1][1] = cosA + y * y * sCosA;
	out[1][2] = y * z * sCosA - x * sinA;

	out[2][0] = z * x * sCosA - y * sinA;
	out[2][1] = z * y * sCosA + x * sinA;
	out[2][2] = cosA + z * z * sCosA;

	out[3][3] = 1;

	return out;
}

const Matrix4x4 Matrix4x4::fromAxisAngle(const Vector3& axis, float angle)
{
	Matrix4x4 out;

	float sinA = sin(angle);
	float cosA = cos(angle);
	float sCosA = 1 - cosA;

	out[0][0] = cosA + axis.x * axis.x * sCosA;
	out[0][1] = axis.x * axis.y * sCosA - axis.z * sinA;
	out[0][2] = axis.x * axis.z * sCosA + axis.y * sinA;

	out[1][0] = axis.y * axis.x * sCosA + axis.z * sinA;
	out[1][1] = cosA + axis.y * axis.y * sCosA;
	out[1][2] = axis.y * axis.z * sCosA - axis.x * sinA;

	out[2][0] = axis.z * axis.x * sCosA - axis.y * sinA;
	out[2][1] = axis.z * axis.y * sCosA + axis.x * sinA;
	out[2][2] = cosA + axis.z * axis.z * sCosA;

	out[3][3] = 1;

	return out;
}

const Matrix4x4 Matrix4x4::fromAxisAngle(const Vector3& axis)
{
	Matrix4x4 out;

	float angle = Vector3::magnitude(axis);
	Vector3 uAxis = Vector3::normalize(axis);

	float sinA = sin(angle);
	float cosA = cos(angle);
	float sCosA = 1 - cosA;

	out[0][0] = cosA + uAxis.x * uAxis.x * sCosA;
	out[0][1] = uAxis.x * uAxis.y * sCosA - uAxis.z * sinA;
	out[0][2] = uAxis.x * uAxis.z * sCosA + uAxis.y * sinA;

	out[1][0] = uAxis.y * uAxis.x * sCosA + uAxis.z * sinA;
	out[1][1] = cosA + uAxis.y * uAxis.y * sCosA;
	out[1][2] = uAxis.y * uAxis.z * sCosA - uAxis.x * sinA;

	out[2][0] = uAxis.z * uAxis.x * sCosA - uAxis.y * sinA;
	out[2][1] = uAxis.z * uAxis.y * sCosA + uAxis.x * sinA;
	out[2][2] = cosA + uAxis.z * uAxis.z * sCosA;

	out[3][3] = 1;

	return out;
}

const Matrix4x4 Matrix4x4::fromAxes(const Vector3& forward, const Vector3& up)
{
	Matrix4x4 out;
	Vector3 right = Vector3::cross(up, forward);

	out[0][0] = right.x;
	out[0][1] = right.y;
	out[0][2] = right.z;

	out[1][0] = up.x;
	out[1][1] = up.y;
	out[1][2] = up.z;

	out[2][0] = forward.x;
	out[2][1] = forward.y;
	out[2][2] = forward.z;

	out[3][3] = 1;

	return out;
}

const Matrix4x4 Matrix4x4::fromAxes(const Vector3& forward, const Vector3& up,
	const Vector3& right)
{
	Matrix4x4 out;

	out[0][0] = right.x;
	out[0][1] = right.y;
	out[0][2] = right.z;

	out[1][0] = up.x;
	out[1][1] = up.y;
	out[1][2] = up.z;

	out[2][0] = forward.x;
	out[2][1] = forward.y;
	out[2][2] = forward.z;

	out[3][3] = 1;

	return out;
}

const Matrix4x4 Matrix4x4::perspective(float fov, float aspectRatio, float zNear, float zFar)
{
	Matrix4x4 out;

	float tanHalfFOV = tan(fov / 2);
	float zRange = zNear - zFar;

	out[0][0] = 1.0f / (tanHalfFOV * aspectRatio);
	out[1][1] = 1.0f / tanHalfFOV;
	out[2][2] = (-zNear - zFar) / zRange;
	out[3][3] = 0;

	out[2][3] = 2 * zFar * zNear / zRange;
	out[3][2] = 1;

	return out;
}

const Matrix4x4 Matrix4x4::operator*(const Matrix4x4& m4) const
{
	Matrix4x4 out;

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			out[y][x] = matrix[y][0] * m4[0][x] +
						matrix[y][1] * m4[1][x] +
						matrix[y][2] * m4[2][x] +
						matrix[y][3] * m4[3][x];
		}
	}

	return out;
}

const Vector3 Matrix4x4::operator*(const Vector3& v3) const
{
	float nx = matrix[0][0] * v3.x + matrix[0][1] * v3.y + matrix[0][2] * v3.z + matrix[0][3];
	float ny = matrix[1][0] * v3.x + matrix[1][1] * v3.y + matrix[1][2] * v3.z + matrix[1][3];
	float nz = matrix[2][0] * v3.x + matrix[2][1] * v3.y + matrix[2][2] * v3.z + matrix[2][3];

	return Vector3(nx, ny, nz);
}

float* Matrix4x4::operator[](int y)
{
	return matrix[y];
}

float* Matrix4x4::operator[](int y) const
{
	return const_cast<float*>(matrix[y]);
}
