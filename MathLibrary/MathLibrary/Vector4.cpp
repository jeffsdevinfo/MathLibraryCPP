#include "Vector4.h"

void MathLibraryJSS::Vector4::operator=(MathLibraryJSS::Vector4& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
}

MathLibraryJSS::Vector4 MathLibraryJSS::Vector4::operator+(const MathLibraryJSS::Vector4& rhs)
{
	return MathLibraryJSS::Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
}

MathLibraryJSS::Vector4 MathLibraryJSS::Vector4::operator-(const MathLibraryJSS::Vector4& rhs)
{
	return MathLibraryJSS::Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}

MathLibraryJSS::Vector4 MathLibraryJSS::Vector4::operator*(const MathLibraryJSS::Vector4& rhs)
{
	return MathLibraryJSS::Vector4(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
}

MathLibraryJSS::Vector4 MathLibraryJSS::Vector4::operator*(const float& rhv)
{
	return MathLibraryJSS::Vector4(x * rhv, y * rhv, z * rhv, w * rhv);
}

bool MathLibraryJSS::Vector4::operator==(const MathLibraryJSS::Vector4& rhs)
{
	float default_Tol = MathHelpers::DEFAULT_TOLERANCE;
	if (abs(x - rhs.x) > default_Tol)
		return false;
	else if (abs(y - rhs.y) > default_Tol)
		return false;
	else if (abs(z - rhs.z) > default_Tol)
		return false;
	else if (abs(w - rhs.w) > default_Tol)
		return false;
	return true;
}

bool MathLibraryJSS::Vector4::operator!=(const MathLibraryJSS::Vector4& rhs)
{
	float default_Tol = MathHelpers::DEFAULT_TOLERANCE;
	if (abs(x - rhs.x) > default_Tol)
		return true;
	else if (abs(y - rhs.y) > default_Tol)
		return true;
	else if (abs(z - rhs.z) > default_Tol)
		return true;
	else if (abs(w - rhs.w) > default_Tol)
		return true;
	return false;
}

float MathLibraryJSS::Vector4::Dot(const MathLibraryJSS::Vector4 inpVec) const
{
	return x * inpVec.x + y * inpVec.y + z * inpVec.z;
}

MathLibraryJSS::Vector4 MathLibraryJSS::Vector4::SourceToDestVec(const MathLibraryJSS::Vector4& destVec) const
{
	return MathLibraryJSS::Vector4(destVec.x - x, destVec.y - y, destVec.z - z, 0);
}

MathLibraryJSS::Vector4 MathLibraryJSS::Vector4::Cross(const MathLibraryJSS::Vector4& other) const
{
	return MathLibraryJSS::Vector4(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x, w);
}

float MathLibraryJSS::Vector4::Magnitude() const
{
	return sqrt(x * x + y * y + z * z);
}

MathLibraryJSS::Vector4 MathLibraryJSS::Vector4::normalized() const
{
	float mag = Magnitude();
	return MathLibraryJSS::Vector4(x / mag, y / mag, z / mag, w);
}

float MathLibraryJSS::Vector4::AngleDegreesBetweenVector(const MathLibraryJSS::Vector4 other) const
{
	return cosf(Dot(other.normalized()) / (Magnitude() * other.Magnitude()));
}

void MathLibraryJSS::Vector4::Normalize()
{
	float mag = Magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
}