#pragma once
#include "MathHelpers.h"
#include <cmath>

namespace MathLibraryJSS
{
	class Vector4
	{
	private:
		float x, y, z, w;
	public:
		Vector4() { x = y = z = w = 0; }

		//copy constructor (must take a ref)
		Vector4(const Vector4& vec) : x(vec.x), y(vec.y), z(vec.z), w(vec.w) {};
		Vector4(float inputX, float inputY, float inputZ, float inputW) : x(inputX), y(inputY), z(inputZ), w(inputW) {};

		//operators
		void operator=(Vector4& rhs);
		Vector4 operator+(const Vector4& rhs);
		Vector4 operator-(const Vector4& rhs);
		Vector4 operator*(const Vector4& rhs);
		Vector4 operator*(const float& rhv);
		bool operator==(const Vector4& rhs);
		bool operator!=(const Vector4& rhs);

		// const methods
		float Dot(const Vector4 inpVec)const;
		Vector4 SourceToDestVec(const Vector4& destVec)const;
		Vector4 Cross(const Vector4& other) const;
		float Magnitude() const;
		Vector4 normalized() const;
		float AngleDegreesBetweenVector(const Vector4 other) const;

		// non-const
		void Normalize();

		//getters
		float X() const { return x; };
		float Y() const { return y; };
		float Z() const { return z; };
		float W() const { return w; };

		//setters
		void X(const float& inpVal) { x = inpVal; };
		void Y(const float& inpVal) { y = inpVal; };
		void Z(const float& inpVal) { z = inpVal; };
		void W(const float& inpVal) { w = inpVal; };

		//Static Utility
		static Vector4* Zero() { return new Vector4(0, 0, 0, 0); }
	};
}