#ifndef VECTOR2_HPP
#define VECTOR2_HPP

/**
 * 2-dimensional vector with x and y coordinates
 */
class Vector2
{
	public:
		/**
		 * Creates a new Vector2 with its x and y components
		 * both 0
		 */
		Vector2();
		/**
		 * Creates a new Vector2 with the given x and y
		 * components
		 *
		 * @param x the x component
		 * @param y the y component
		 */
		Vector2(float x, float y);
		/**
		 * Creates a new Vector2 by copying the corresponding
		 * components of Vector2 v2
		 */
		Vector2(const Vector2& v2);

		/** @brief calculates the dot product of this vector and v2 */
		float dot(const Vector2& v2) const;

		/** @brief calculates the magnitude (length) of the vector */
		float magnitude() const;
		/** @brief calculates the magnitude^2 of the vector */
		float magSq() const;
		/** @brief calculates a normalized (unit) vector */
		Vector2 normalize() const;

		/**
		 * Compares whether two vectors are equal by testing whether
		 * all of their corresponding components are equal
		 */
		bool operator==(const Vector2&) const;
		bool operator!=(const Vector2&) const;

		/** @brief negates the vector */
		Vector2 operator-() const;

		/** @brief adds two vectors together */
		Vector2 operator+(const Vector2&) const;
		/** @brief subtracts two vectors */
		Vector2 operator-(const Vector2&) const;
		/** @brief multiplies two vectors */
		Vector2 operator*(const Vector2&) const;
		/** @brief divides two vectors */
		Vector2 operator/(const Vector2&) const;

		/** @brief adds a number to the vector */
		Vector2 operator+(float) const;
		/** @brief subtracts a number from a vector */
		Vector2 operator-(float) const;
		/** @brief multiplies a number by a vector */
		Vector2 operator*(float) const;
		/** @brief divides a vector by a number */
		Vector2 operator/(float) const;

		/** @brief adds a vector to this vector*/
		Vector2& operator+=(const Vector2&);
		/** @brief subtracts a vector from this vector */
		Vector2& operator-=(const Vector2&);
		/** @brief multiplies a vector by this vector */
		Vector2& operator*=(const Vector2&);
		/** @brief divides this vector by a vector */
		Vector2& operator/=(const Vector2&);

		/** @brief adds a number to this vector */
		Vector2& operator+=(float);
		/** @brief subtracts a number from this vector */
		Vector2& operator-=(float);
		/** @brief multiplies a number by this vector */
		Vector2& operator*=(float);
		/** @brief divides this vector by a number */
		Vector2& operator/=(float);

		/** @brief indexes the components of the vector */
		float operator[](int);
		const float operator[](int) const;

		float x, y;
	private:
};

#endif
