#pragma once
#include "Vector3.h"
namespace MathLibraryJSS
{
	class Matrix3
	{
	private:
		float mXx, mYx, mZx;
		float mXy, mYy, mZy;
		float mXz, mYz, mZz;

	public:
#pragma region GetterSetter
		float Xx() { return mXx; }; void Xx(const float& input) { mXx = input; };
		float Xy() { return mXy; }; void Xy(const float& input) { mXy = input; };
		float Xz() { return mXz; }; void Xz(const float& input) { mXz = input; };
		float Yx() { return mYx; }; void Yx(const float& input) { mYx = input; };
		float Yy() { return mYy; }; void Yy(const float& input) { mYy = input; };
		float Yz() { return mYz; }; void Yz(const float& input) { mYz = input; };
		float Zx() { return mZx; }; void Zx(const float& input) { mZx = input; };
		float Zy() { return mZy; }; void Zy(const float& input) { mZy = input; };
		float Zz() { return mZz; }; void Zz(const float& input) { mZz = input; };
#pragma endregion GetterSetter

		Matrix3() { Set(0, 0, 0, 0, 0, 0, 0, 0, 0); }
		Matrix3(const Matrix3& inpMat);
		Matrix3(float inp_mXx, float inp_mXy, float inp_mXz,
			float inp_mYx, float inp_mYy, float inp_mYz,
			float inp_mZx, float inp_mZy, float inp_mZz);

		void Set(float inp_mXx, float inp_mXy, float inp_mXz,
			float inp_mYx, float inp_mYy, float inp_mYz,
			float inp_mZx, float inp_mZy, float inp_mZz);

		Matrix3 operator*(const Matrix3& rhs) const;
		Matrix3 operator*(const float& rhv) const;
		Vector3 operator*(const Vector3& rhs) const;
		bool operator==(const Matrix3& rhs) const;
		bool operator!=(const Matrix3& rhs) const;

		void SetRotateX(const float& AngleInDegrees);
		void SetRotateY(const float& AngleInDegrees);
		void SetRotateZ(const float& AngleInDegrees);
	};
}