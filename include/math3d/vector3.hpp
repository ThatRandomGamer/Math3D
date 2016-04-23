#ifndef VECTOR3_HPP
#define VECTOR3_HPP

class Quaternion;

/**
 * 3-dimensional vector with x, y, and z coordinates
 */
class Vector3
{
	public:
		/** @brief calculates the dot product of vectors a and b */
		static float dot(const Vector3& a, const Vector3& b);
		/** @brief calculates the cross product of vectors a and b */
		static const Vector3 cross(const Vector3& a, const Vector3& b);

		/** @brief calculates the magnitude (length) of the vector */
		static float magnitude(const Vector3&);
		/** @brief calculates the magnitude^2 of the vector */
		static float magSq(const Vector3&);
		/** @brief calculates a normalized (unit) vector */
		static const Vector3 normalize(const Vector3&);

		/**
		 * Creates a new Vector3 with its x, y, and z components
		 * all 0
		 */
		Vector3();
		/**
		 * Creates a new Vector3 with the given x, y, and z
		 * components
		 *
		 * @param x the x component
		 * @param y the y component
		 * @param z the z component
		 */
		Vector3(float x, float y, float z);
		/**
		 * Creates a new Vector3 by copying the corresponding
		 * components of Vector3 v3
		 */
		Vector3(const Vector3& v3);

		/**
		 * rotates the vector by the given quaternion
		 *
		 * @param rot the quaternion to rotate by
		 */
		const Vector3 rotateBy(const Quaternion& rot) const;
		/**
		 * Rotates the vector around the axis by the given angle
		 *
		 * @param axis the axis to rotate around
		 * @param angle the angle to rotate
		 */
		const Vector3 rotateBy(const Vector3& axis, float angle) const;

		/**
		 * Compares whether two vectors are equal by testing whether
		 * all of their corresponding components are equal
		 */
		bool operator==(const Vector3&);
		bool operator!=(const Vector3&);

		/** @brief negates the vector */
		const Vector3 operator-() const;

		/** @brief adds two vectors together */
		const Vector3 operator+(const Vector3&) const;
		/** @brief subtracts two vectors */
		const Vector3 operator-(const Vector3&) const;
		/** @brief multiplies two vectors */
		const Vector3 operator*(const Vector3&) const;
		/** @brief divides two vectors */
		const Vector3 operator/(const Vector3&) const;

		/** @brief adds a number to the vector */
		const Vector3 operator+(float) const;
		/** @brief subtracts a number from the vector */
		const Vector3 operator-(float) const;
		/** @brief multiplies a number by the vector */
		const Vector3 operator*(float) const;
		/** @brief divides the vector by a number */
		const Vector3 operator/(float) const;


		/** @brief adds a vector to this vector */
		Vector3& operator+=(const Vector3&);
		/** @brief subtractes a vector from this vector */
		Vector3& operator-=(const Vector3&);
		/** @brief multiplies a vector by this vector */
		Vector3& operator*=(const Vector3&);
		/** @brief divides this vector by a vector */
		Vector3& operator/=(const Vector3&);

		/** @brief adds a number to this vector */
		Vector3& operator+=(float);
		/** @brief subtracts a number from this vector */
		Vector3& operator-=(float);
		/** @brief multiplies a number by this vector */
		Vector3& operator*=(float);
		/** @brief divides this vector by a number */
		Vector3& operator/=(float);

		/** @brief indexes the components of the vector */
		float operator[](int);

		float x, y, z;
	private:
};

#endif
