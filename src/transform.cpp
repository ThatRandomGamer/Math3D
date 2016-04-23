#include "transform.hpp"

static const Quaternion getLookAtRotation(const Vector3&, const Vector3&, const Vector3&);

Transform::Transform()
: position(Vector3()), rotation(Quaternion(0, 0, 0, 1)), scale(Vector3(1, 1, 1))
{
}

Transform::Transform(const Vector3& position, const Quaternion& rotation, const Vector3& scale)
: position(Vector3(position)), rotation(Quaternion(rotation)), scale(Vector3(scale))
{
}

const Matrix4x4 Transform::getTransformation()
{
	return Matrix4x4::position(position)
		* Matrix4x4::rotation(rotation) * Matrix4x4::scale(scale);
}

Transform& Transform::translateBy(float x, float y, float z)
{
	position += Vector3(x, y, z).rotateBy(rotation);

	return *this;
}

Transform& Transform::translateBy(const Vector3& v3)
{
	position += v3.rotateBy(rotation);

	return *this;
}

Transform& Transform::rotateBy(const Quaternion& rot)
{
	rotation = rotation.rotateBy(rot);

	return *this;
}

Transform& Transform::lookAt(float x, float y, float z)
{
	rotation = getLookAtRotation(position, Vector3(x, y, z), Vector3(0, 1, 0));

	return *this;
}

Transform& Transform::lookAt(const Vector3& point)
{
	rotation = getLookAtRotation(position, point, Vector3(0, 1, 0));

	return *this;
}

static const Quaternion getLookAtRotation(const Vector3& a, const Vector3& b, const Vector3& up)
{
	return Quaternion::fromMatrix(Matrix4x4::fromAxes(Vector3::normalize(b - a), up));
}
