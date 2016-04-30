#include <iostream>
#include <cstdio>
#include "math3d/math3d.hpp"

void print(const Vector2&);
void print(const Vector3&);
void print(const Quaternion&);
void print(const Matrix4x4&);
void print(const Transform&);

int main()
{
	std::cout << "Math3D Test Program" << std::endl;

	Vector2 v2(2, 3);

	v2 = v2 + 1;

	print(v2);
	std::cout << v2.magnitude() << std::endl;
	std::cout << v2.dot(Vector2(0, 1)) << std::endl;

	std::cin.get();
	return 0;
}

void print(const Vector2& v2)
{
	printf("(%.2f, %.2f)\n", v2[0], v2[1]);
}

void print(const Vector3& v3)
{
	printf("(%.2f, %.2f, %.2f)\n", v3[0], v3[1], v3[2]);
}

void print(const Quaternion& q)
{
	printf("(%.2f, %.2f, %.2f, %.2f)\n", q[0], q[1], q[2], q[3]);
}

void print(const Matrix4x4& m4)
{
	for (int y = 0; y < 4; y++)
	{
		printf("%.2f %.2f %.2f %.2f\n", m4[y][0], m4[y][1], m4[y][2], m4[y][3]);
	}
}
