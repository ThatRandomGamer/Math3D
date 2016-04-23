#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "vector3.hpp"
#include "quaternion.hpp"
#include "matrix4x4.hpp"

/**
 * Represents a transformation in 3D with a position,
 * rotation, and a scale
 */
class Transform
{
	public:
		/**
		 * Creates a new default Transform object with a position of
		 * (0, 0, 0), a rotation of (0, 0, 0, 1) and a scale of (1, 1, 1)
		 */
		Transform();
		/**
		 * Creates a new Quaternion from a given position, rotation,
		 * and scale
		 *
		 * @param position the position of the transform
		 * @param rotation the rotation of the transform
		 * @param scale the scale of the transform
		 */
		Transform(const Vector3& position, const Quaternion& rotation, const Vector3& scale);

		/**
		 * Creates a transformation matrix using the transform's
		 * position, rotation, and scale
		 */
		const Matrix4x4 getTransformation();

		/**
		 * translates the transform by the given (x, y, z)
		 * vector
		 *
		 * @param x the x component of the vector
		 * @param y the y component of the vector
		 * @param z the z component of the vector
		 */
		Transform& translateBy(float x, float y, float z);
		/**
		 * translates the transform by the given (x, y, z)
		 * vector
		 *
		 * @param v3 the vector to translate by
		 */
		Transform& translateBy(const Vector3& v3);

		/**
		 * Rotates the transform by the given rotation
		 *
		 * @param rot the rotation to rotate by
		 */
		Transform& rotateBy(const Quaternion& rot);

		/**
		 * Orients the transform so that it looks at the (x, y, z)
		 * point
		 *
		 * @param x the x component of the point
		 * @param y the y component of the point
		 * @param z the z component of the point
		 */
		Transform& lookAt(float x, float y, float z);
		/**
		 * Orients the transform so that it looks at the (x, y, z)
		 * point
		 *
		 * @param point the point to look at
		 */
		Transform& lookAt(const Vector3& point);

		Vector3 position;
		Quaternion rotation;
		Vector3 scale;
	private:
};

#endif
