#pragma once
#include "Vector4.h"

namespace MathLibraryJSS
{
	class Matrix4
	{

	private:
#pragma region Privates
		float mXx, mYx, mZx, mTx;
		float mXy, mYy, mZy, mTy;
		float mXz, mYz, mZz, mTz;
		float mXw, mYw, mZw, mTw;
#pragma endregion Privates

	public:
#pragma region Constructors
		//default constructor
		Matrix4() {
			Set(0, 0, 0, 0,
				0, 0, 0, 0,
				0, 0, 0, 0,
				0, 0, 0, 0);
		}

		//identiy mat constructor
		Matrix4(bool bIdentityMatrix) {
			float defaultParam = 0.0f;
			if (bIdentityMatrix)
				defaultParam = 1;
			Set(defaultParam, 0, 0, 0,
				0, defaultParam, 0, 0,
				0, 0, defaultParam, 0,
				0, 0, 0, defaultParam);
		}

		//copy constructor
		Matrix4(const Matrix4& inpMat);

		//item constructor
		Matrix4(float inp_mXx, float inp_mXy, float inp_mXz, float inp_mXw,
			float inp_mYx, float inp_mYy, float inp_mYz, float inp_mYw,
			float inp_mZx, float inp_mZy, float inp_mZz, float inp_mZw,
			float inp_mTx, float inp_mTy, float inp_mTz, float inp_mTw);
#pragma endregion Constructors

#pragma region Getter Setter
		//set items
		void Set(float inp_mXx, float inp_mXy, float inp_mXz, float inp_mXw,
			float inp_mYx, float inp_mYy, float inp_mYz, float inp_mYw,
			float inp_mZx, float inp_mZy, float inp_mZz, float inp_mZw,
			float inp_mTx, float inp_mTy, float inp_mTz, float inp_mTw);

		//set with class
		void Set(const Matrix4 refMat);

		float Xx() { return mXx; }; void Xx(const float& input) { mXx = input; };
		float Xy() { return mXy; }; void Xy(const float& input) { mXy = input; };
		float Xz() { return mXz; }; void Xz(const float& input) { mXz = input; };
		float Xw() { return mXw; }; void Xw(const float& input) { mXw = input; };

		float Yx() { return mYx; }; void Yx(const float& input) { mYx = input; };
		float Yy() { return mYy; }; void Yy(const float& input) { mYy = input; };
		float Yz() { return mYz; }; void Yz(const float& input) { mYz = input; };
		float Yw() { return mYw; }; void Yw(const float& input) { mYw = input; };

		float Zx() { return mZx; }; void Zx(const float& input) { mZx = input; };
		float Zy() { return mZy; }; void Zy(const float& input) { mZy = input; };
		float Zz() { return mZz; }; void Zz(const float& input) { mZz = input; };
		float Zw() { return mZw; }; void Zw(const float& input) { mZw = input; };

		float Tx() { return mTx; }; void Tx(const float& input) { mTx = input; };
		float Ty() { return mTy; }; void Ty(const float& input) { mTy = input; };
		float Tz() { return mTz; }; void Tz(const float& input) { mTz = input; };
		float Tw() { return mTw; }; void Tw(const float& input) { mTw = input; };
#pragma endregion GetterSetter

#pragma region operators
		Matrix4 operator*(const Matrix4& rhs) const;
		Matrix4 operator*(const float& rhv) const;
		Vector4 operator*(const Vector4& rhs) const;
		Matrix4& operator=(const Matrix4& rhv);
		bool operator==(const Matrix4& rhs) const;
		bool operator!=(const Matrix4& rhs) const;
#pragma endregion operators

#pragma region Rotate Translate
		void SetRotateX(const float& AngleInDegrees);
		void SetRotateY(const float& AngleInDegrees);
		void SetRotateZ(const float& AngleInDegrees);
		void SetTranslation(const Vector4& transVec);

		void RotateX(const float& AngleInDegrees);
		void RotateY(const float& AngleInDegrees);
		void RotateZ(const float& AngleInDegrees);
		void Translate(const Vector4& transVec);
#pragma endregion Rotate Translate
	};
}