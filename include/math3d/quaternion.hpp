#ifndef QUATERNION_HPP
#define QUATERNION_HPP

class Vector3;
class Matrix4x4;

#include "vector3.hpp"
#include "matrix4x4.hpp"

/**
 * Quaternion representation of a rotation in 3D space
 * using 4 (x, y, z, w) components
 */
class Quaternion
{
	public:
		/**
		 * Creates a quaternion from an (x, y, z) axis and an angle
		 *
		 * Note: the axis must be a unit (normalized) vector
		 *
		 * @param x the x component of the axis
		 * @param y the y component of the axis 
		 * @param z the z component of the axis 
		 * @param angle the angle by which to rotate
		 */
		static const Quaternion fromAxisAngle(float x, float y, float z, float angle);
		/**
		 * Creates a quaternion from a Vector3 axis and an angle
		 *
		 * Note: the axis must be a unit (normalized) vector
		 *
		 * @param axis the normalized axis to rotate about
		 * @param angle the angle by which to rotate
		 */
		static const Quaternion fromAxisAngle(const Vector3& axis, float angle);
		/**
		 * Creates a quaternion from a vector by using its magnitude
		 * for the angle of rotation, and its normalized vector as an axis
		 *
		 * @param axis the vector containing the axis and the angle of the rotation
		 */
		static const Quaternion fromAxisAngle(const Vector3& axis);

		/**
		 * Creates a quaternion from (x, y, z) euler angles
		 *
		 * @param x the x axis rotation
		 * @param y the y axis rotation
		 * @param z the z axis rotation
		 */
		static const Quaternion fromEulerAngles(float x, float y, float z);
		/**
		 * Creates a quaternion from (x, y, z) euler angles contained
		 * within the vector angles
		 *
		 * @param angles the vector containing the euler angles
		 */
		static const Quaternion fromEulerAngles(const Vector3& angles);

		/**
		 * Creates a quaternion from the given matrix
		 * 
		 * @param m4 the matrix containing the rotation 
		 */
		static const Quaternion fromMatrix(const Matrix4x4& m4);

		/**
		 * Creates a new Quaternion from its (x, y, z, w) components
		 *
		 * @param x the x component of the quaternion
		 * @param y the y component of the quaternion
		 * @param z the z component of the quaternion
		 * @param w the w component of the quaternion
		 */
		Quaternion(float x, float y, float z, float w);
		/**
		 * Creates a new quaternion by copying the corresponding
		 * components of quaternion q
		 */
		Quaternion(const Quaternion& q);

		/** @brief calculates the magnitude (length) of the quaternion */
		static float magnitude(const Quaternion&);
		/** @brief calculates the magnitude^2 of the quaternion */
		static float magSq(const Quaternion&);
		/** @brief calculates a normalized (unit) quaternion */
		static const Quaternion normalize(const Quaternion&);
		/** @brief calculates the conjugate of the quaternion */
		static const Quaternion conjugate(const Quaternion&);

		/** @brief calculates the dot product of quaternions a and b */
		static float dot(const Quaternion& a, const Quaternion& b);

		/**
		 * Linearly interpolates between two vectors by a given percentage
		 *
		 * @param from the quaternion to lerp from
		 * @param to the quaternion to lerp to
		 * @param inc the percentage increment to interpolate between the quaternions
		 * @param shortest whether or not to take the shortest path of interpolation
		 */
		static const Quaternion nlerp(const Quaternion& from, const Quaternion& to, float inc,
			bool shortest = true);
		/**
		 * Spherical-linear interpolation between two vectors by a given percentage
		 *
		 * @param from the quaternion to lerp from
		 * @param to the quaternion to lerp to
		 * @param inc the percentage increment to interpolate between the quaternions
		 * @param shortest whether or not to take the shortest path of interpolation
		 */
		static const Quaternion slerp(const Quaternion& from, const Quaternion& to, float inc,
			bool shortest = true);

		/**
		 * Compares whether two quaternions are equal by testing whether
		 * all of their corresponding components are equal
		 */
		bool operator==(const Quaternion&);
		bool operator!=(const Quaternion&);

		/** @brief rotates the quaternion by the given quaternion */
		const Quaternion rotateBy(const Quaternion&);

		/** @brief negates the quaternion */
		const Quaternion operator-() const;

		/** @brief adds two quaternions together */
		const Quaternion operator+(const Quaternion&) const;
		/** @brief subtracts two quaternions */
		const Quaternion operator-(const Quaternion&) const;
		
		/** @brief multiplies two quaternions together */
		const Quaternion operator*(const Quaternion&) const;
		/** @brief multiplies a vector by a quaternion */
		const Quaternion operator*(const Vector3&) const;
		/** @brief multiplies a quaternion by a number */
		const Quaternion operator*(float) const;

		/**
		 * Gets a normalized (unit) vector facing the corresponding direction
		 * relative to the orientation of the quaternion
		 */
		const Vector3 forward();
		const Vector3 back();
		const Vector3 left();
		const Vector3 right();
		const Vector3 up();
		const Vector3 down();

		/** @brief indexes the components of the quaternion */
		float operator[](int);

		float x, y, z, w;
	private:
};

#endif
