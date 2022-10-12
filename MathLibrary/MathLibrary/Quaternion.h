#pragma once
#include "Vector3.h"
#include "Vector4.h"

namespace MathLibraryJSS
{
	class Quaternion
	{
	private:
		float x, y, z, w;
	public:
		Quaternion() { x = y = z = w = 0; }

		//copy constructors
		Quaternion(const Quaternion& quat) : x(quat.x), y(quat.y), z(quat.z), w(quat.w) {};
		Quaternion(float inputX, float inputY, float inputZ, float inputW) : x(inputX), y(inputY), z(inputZ), w(inputW) {};
		Quaternion(const Vector3& inputVec3) : x(inputVec3.X()), y(inputVec3.Y()), z(inputVec3.Z()), w(0) {};

		//operators
		void operator=(const Quaternion& rhs);
		Quaternion operator+(const Quaternion& rhs);
		Quaternion operator-(const Quaternion& rhs);
		Quaternion operator*(const Quaternion& rhs);
		Quaternion operator*(const float& rhs);

		//operations
		Quaternion AngleAxis(float angleToRotate, Vector3 axisToRotateOn);
		Vector3 Vec3() { return Vector3(x, y, z); }
		Vector4 Vec4() { return Vector4(x, y, z, w); }

		void normalize();

		//statics
		static Quaternion AngleAxisPoint(Vector3 pointToRotate, float angleToRotate, Vector3 axisToRotateOn);
		static Vector3 AngleAxisPointVec3(Vector3 pointToRotate, float angleToRotate, Vector3 axisToRotateOn);

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
	};

}