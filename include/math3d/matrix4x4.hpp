#ifndef MATRIX4X4_HPP
#define MATRIX4X4_HPP

#include "vector3.hpp"
#include "quaternion.hpp"

/**
 * A 4x4 transformation matrix representing a
 * position and a rotation in 3-dimensional space
 */
class Matrix4x4
{
	public:
		/**
		 * Creates a new Matrix4x4 object and initializes so that it
		 * contains the 4x4 identity matrix
		 */
		static Matrix4x4 identity();
		
		/**
		 * Creates a new Matrix4x4 object and initializes it with
		 * an (x, y, z) position
		 *
		 * @param x the x component of the position
		 * @param y the y component of the position
		 * @param z the z component of the position
		 */
		static Matrix4x4 position(float x, float y, float z);
		/**
		 * Creates a new Matrix4x4 object and initializes it with
		 * an (x, y, z) position
		 *
		 * @param pos the vector containing the position
		 */
		static Matrix4x4 position(const Vector3& pos);

		/**
		 * Creates a new Matrix4x4 object and initializes it with
		 * an (x, y, z) scale
		 *
		 * @param x the x component of the scale
		 * @param y the y component of the scale
		 * @param z the z component of the scale
		 */
		static Matrix4x4 scale(float x, float y, float z);
		/**
		 * Creates a new Matrix4x4 object and initializes it with
		 * an (x, y, z) scale
		 *
		 * @param scale the vector containing the scale
		 */
		static Matrix4x4 scale(const Vector3& scale);

		/**
		 * Creates a new Matrix4x4 object and initializes it with
		 * a rotation consisting of (x, y, z) euler angles
		 *
		 * @param x the x axis rotation
		 * @param y the y axis rotation
		 * @param z the z axis rotation
		 */
		static Matrix4x4 rotation(float x, float y, float z);
		/**
		 * Creates a new Matrix4x4 object and initializes it with
		 * a rotation consisting of (x, y, z) euler angles
		 *
		 * @param rot the rotations for the x, y, and z axes
		 */
		static Matrix4x4 rotation(const Vector3& rot);

		/**
		 * Creates a new Matrix4x4 object and initializes it with
		 * a quaternion (x, y, z, w) rotation
		 *
		 * @param x the x component of the rotation
		 * @param y the y component of the rotation
		 * @param z the z component of the rotation
		 * @param w the w component of the rotation
		 */
		static Matrix4x4 rotation(float x, float y, float z, float w);
		/**
		 * Creates a new Matrix4x4 object and initializes it with
		 * a quaternion (x, y, z, w) rotation
		 *
		 * @param rot the rotation quaternion
		 */
		static Matrix4x4 rotation(const Quaternion& rot);	

		/**
		 * Creates a new Matrix4x4 object and initializes it with
		 * a rotation from an (x, y, z) vector axis and an angle
		 *
		 * Note: the axis must be a unit (normalized) vector
		 *
		 * @param x the x component of the axis
		 * @param y the y component of the axis
		 * @param z the z component of the axis
		 * @param angle the angle of rotation
		 */
		static Matrix4x4 fromAxisAngle(float x, float y, float z, float angle);
		/**
		 * Creates a new Matrix4x4 object and initializes it with
		 * a rotation from an (x, y, z) vector axis and an angle
		 *
		 * Note: the axis must be a unit (normalized) vector
		 *
		 * @param axis the axis of rotation
		 * @param angle the angle of rotation
		 */
		static Matrix4x4 fromAxisAngle(const Vector3& axis, float angle);
		/**
		 * Creates a new Matrix4x4 object and initializes it with
		 * a rotation from a vector by using its magnitude for the angle of
		 * rotation and its normalized vector as an axis
		 *
		 * Note: the axis must be a unit (normalized) vector
		 *
		 * @param axis the vector containing the axis and the angle of rotation
		 */
		static Matrix4x4 fromAxisAngle(const Vector3& axis);

		/**
		 * Creates a new Matrix4x4 object and initializes it with
		 * a rotation created from a normalized (unit) forward vector
		 * and a normalized up vector
		 *
		 * @param forward the forward direction vector
		 * @param up the up direction vector
		 */
		static Matrix4x4 fromAxes(const Vector3& forward, const Vector3& up);
		/**
		 * Creates a new Matrix4x4 object and initializes it with
		 * a rotation created from a normalized (unit) forward vector,
		 * a normalized up vector, and a normalized right vector
		 *
		 * @param forward the forward direction vector
		 * @param up the up direction vector
		 * @param right the right direction vector
		 */
		static Matrix4x4 fromAxes(const Vector3& forward, const Vector3& up, const Vector3& right);

		/**
		 * Creates a new Matrix4x4 object and initializes it with a
		 * perspective projection matrix created from the given fov,
		 * aspect ratio, near, and far values
		 *
		 * @param fov the field-of-view for the projection
		 * @param aspectRatio the aspect ratio for the projection
		 * @param zNear the near value for the projection
		 * @param zFar the far value for the projection
		 */
		static Matrix4x4 perspective(float fov, float aspectRatio, float zNear, float zFar);

		/**
		 * Creates a new Matrix4x4 and initializes all of its
		 * components to 0
		 */
		Matrix4x4();
		/**
		 * Creates a new Matrix4x4 and ininitialzes its matrix
		 * to the matrix of the given Matrix4x4 object
		 */
		Matrix4x4(const Matrix4x4&);

		/** @brief calculates the determinant of the given matrix */
		float determinant() const;
		/** @brief calculates the inverse of the given matrix */
		Matrix4x4 inverse() const;
		/** @brief calculates the transpose of the given matrix */
		Matrix4x4 transpose() const;

		/** @brief multiplies two matrices together using matrix multiplication */
		Matrix4x4 operator*(const Matrix4x4&) const;

		/** @brief transforms a vector by the matrix using matrix multiplication */
		Vector3 operator*(const Vector3&) const;

		/** @brief indexes the components of the matrix in [column][row] or [y][x] format */
		float* operator[](int);
		const float* operator[](int) const;

		float matrix[4][4];
	private:
};

#endif
