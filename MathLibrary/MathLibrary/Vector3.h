#pragma once
#include "MathHelpers.h"

namespace MathLibraryJSS 
{
	class Vector3
	{
	private:
		float x, y, z;
	public:
		Vector3() { x = y = z = 0; }

		//copy constructor (must take a ref)
		Vector3(const Vector3& vec) : x(vec.x), y(vec.y), z(vec.z) {};
		Vector3(float inputX, float inputY, float inputZ) : x(inputX), y(inputY), z(inputZ) {};

		//operators
		void operator=(const Vector3& rhs);
		Vector3 operator+(const Vector3& rhs);
		Vector3 operator-(const Vector3& rhs);
		Vector3 operator*(const Vector3& rhs);
		Vector3 operator*(const float& rhv);
		bool operator==(const Vector3& rhs);
		bool operator!=(const Vector3& rhs);

		// const methods
		float Dot(const Vector3 inpVec)const;
		Vector3 SourceToDestVec(const Vector3& destVec)const;
		Vector3 Cross(const Vector3& other) const;
		float Magnitude() const;
		Vector3 normalized() const;
		float AngleDegreesBetweenVector(const Vector3 other) const;

		// non-const
		void Normalize();

		//getters
		float X() const { return x; };
		float Y() const { return y; };
		float Z() const { return z; };

		//setters
		void X(const float& inpVal) { x = inpVal; };
		void Y(const float& inpVal) { y = inpVal; };
		void Z(const float& inpVal) { z = inpVal; };

		//Static Utility
		static Vector3* Zero() { return new Vector3(0, 0, 0); }

		~Vector3();
	};
}

