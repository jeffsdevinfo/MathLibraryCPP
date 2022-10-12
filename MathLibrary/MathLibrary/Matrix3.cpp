#include "Matrix3.h"
#include "MathHelpers.h"

MathLibraryJSS::Matrix3::Matrix3(const MathLibraryJSS::Matrix3& inpMat)
{
	Set(inpMat.mXx, inpMat.mXy, inpMat.mXz,
		inpMat.mYx, inpMat.mYy, inpMat.mYz,
		inpMat.mZx, inpMat.mZy, inpMat.mZz);
}

MathLibraryJSS::Matrix3::Matrix3(float inp_mXx, float inp_mXy, float inp_mXz,
	float inp_mYx, float inp_mYy, float inp_mYz,
	float inp_mZx, float inp_mZy, float inp_mZz)
{
	Set(inp_mXx, inp_mXy, inp_mXz,
		inp_mYx, inp_mYy, inp_mYz,
		inp_mZx, inp_mZy, inp_mZz);
}

void MathLibraryJSS::Matrix3::Set(float inp_mXx, float inp_mXy, float inp_mXz,
	float inp_mYx, float inp_mYy, float inp_mYz,
	float inp_mZx, float inp_mZy, float inp_mZz)
{
	mXx = inp_mXx; mYx = inp_mYx; mZx = inp_mZx;
	mXy = inp_mXy; mYy = inp_mYy; mZy = inp_mZy;
	mXz = inp_mXz; mYz = inp_mYz; mZz = inp_mZz;
}

MathLibraryJSS::Matrix3 MathLibraryJSS::Matrix3::operator*(const MathLibraryJSS::Matrix3& rhs) const
{
	return MathLibraryJSS::Matrix3(
		(mXx * rhs.mXx) + (mYx * rhs.mXy) + (mZx * rhs.mXz),
		(mXy * rhs.mXx) + (mYy * rhs.mXy) + (mZy * rhs.mXz),
		(mXz * rhs.mXx) + (mYz * rhs.mXy) + (mZz * rhs.mXz),

		(mXx * rhs.mYx) + (mYx * rhs.mYy) + (mZx * rhs.mYz),
		(mXy * rhs.mYx) + (mYy * rhs.mYy) + (mZy * rhs.mYz),
		(mXz * rhs.mYx) + (mYz * rhs.mYy) + (mZz * rhs.mYz),

		(mXx * rhs.mZx) + (mYx * rhs.mZy) + (mZx * rhs.mZz),
		(mXy * rhs.mZx) + (mYy * rhs.mZy) + (mZy * rhs.mZz),
		(mXz * rhs.mZx) + (mYz * rhs.mZy) + (mZz * rhs.mZz));
}

MathLibraryJSS::Matrix3 MathLibraryJSS::Matrix3::operator*(const float& rhv) const
{
	return MathLibraryJSS::Matrix3(
		mXx * rhv, mXy * rhv, mXz * rhv,
		mYx * rhv, mYy * rhv, mYz * rhv,
		mZx * rhv, mZy * rhv, mZz * rhv
	);
}

MathLibraryJSS::Vector3 MathLibraryJSS::Matrix3::operator*(const Vector3& rhs) const
{
	return Vector3(
		(mXx * rhs.X()) + (mYx * rhs.Y()) + (mZx * rhs.Z()),
		(mXy * rhs.X()) + (mYy * rhs.Y()) + (mZy * rhs.Z()),
		(mXz * rhs.X()) + (mYz * rhs.Y()) + (mZz * rhs.Z()));
}

bool MathLibraryJSS::Matrix3::operator==(const MathLibraryJSS::Matrix3& rhs) const
{
	float default_Tol = MathHelpers::DEFAULT_TOLERANCE;
	if (abs(mXx - rhs.mXx) > default_Tol)
		return false;
	if (abs(mXy - rhs.mXy) > default_Tol)
		return false;
	if (abs(mXz - rhs.mXz) > default_Tol)
		return false;

	if (abs(mYx - rhs.mYx) > default_Tol)
		return false;
	if (abs(mYy - rhs.mYy) > default_Tol)
		return false;
	if (abs(mYz - rhs.mYz) > default_Tol)
		return false;

	if (abs(mZx - rhs.mZx) > default_Tol)
		return false;
	if (abs(mZy - rhs.mZy) > default_Tol)
		return false;
	if (abs(mZz - rhs.mZz) > default_Tol)
		return false;

	return true;
}

bool MathLibraryJSS::Matrix3::operator!=(const MathLibraryJSS::Matrix3& rhs) const
{
	float default_Tol = MathHelpers::DEFAULT_TOLERANCE;
	if (abs(mXx - rhs.mXx) > default_Tol)
		return true;
	if (abs(mXy - rhs.mXy) > default_Tol)
		return true;
	if (abs(mXz - rhs.mXz) > default_Tol)
		return true;

	if (abs(mYx - rhs.mYx) > default_Tol)
		return true;
	if (abs(mYy - rhs.mYy) > default_Tol)
		return true;
	if (abs(mYz - rhs.mYz) > default_Tol)
		return true;

	if (abs(mZx - rhs.mZx) > default_Tol)
		return true;
	if (abs(mZy - rhs.mZy) > default_Tol)
		return true;
	if (abs(mZz - rhs.mZz) > default_Tol)
		return true;

	return false;
}

void MathLibraryJSS::Matrix3::SetRotateX(const float& AngleInDegrees)
{
	float rotationRadians = MathHelpers::DegToRad(AngleInDegrees);
	Set(1, 0, 0,
		0, cos(rotationRadians), sin(rotationRadians),
		0, -sin(rotationRadians), cos(rotationRadians));
}

void MathLibraryJSS::Matrix3::SetRotateY(const float& AngleInDegrees)
{
	float rotationRadians = MathHelpers::DegToRad(AngleInDegrees);
	Set(cos(rotationRadians), 0, -sin(rotationRadians),
		0, 1, 0,
		sin(rotationRadians), 0, cos(rotationRadians));
}

void MathLibraryJSS::Matrix3::SetRotateZ(const float& AngleInDegrees)
{
	float rotationRadians = MathHelpers::DegToRad(AngleInDegrees);
	Set(cos(rotationRadians), sin(rotationRadians), 0,
		-sin(rotationRadians), cos(rotationRadians), 0,
		0, 0, 1);
}