// Fill out your copyright notice in the Description page of Project Settings.
#include "Vector3.h"
#include <cmath>

void MathLibraryJSS::Vector3::operator=(const MathLibraryJSS::Vector3& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
}

MathLibraryJSS::Vector3 MathLibraryJSS::Vector3::operator+(const MathLibraryJSS::Vector3& rhs)
{
	return MathLibraryJSS::Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
}

MathLibraryJSS::Vector3 MathLibraryJSS::Vector3::operator-(const MathLibraryJSS::Vector3& rhs)
{
	return MathLibraryJSS::Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
}

MathLibraryJSS::Vector3 MathLibraryJSS::Vector3::operator*(const MathLibraryJSS::Vector3& rhs)
{
	return MathLibraryJSS::Vector3(x * rhs.x, y * rhs.y, z * rhs.z);
}

MathLibraryJSS::Vector3 MathLibraryJSS::Vector3::operator*(const float& rhv)
{
	return MathLibraryJSS::Vector3(x * rhv, y * rhv, z * rhv);
}

bool MathLibraryJSS::Vector3::operator==(const MathLibraryJSS::Vector3& rhs)
{
	float default_Tol = MathHelpers::DEFAULT_TOLERANCE;
	if (abs(x - rhs.x) > default_Tol)
		return false;
	else if (abs(y - rhs.y) > default_Tol)
		return false;
	else if (abs(z - rhs.z) > default_Tol)
		return false;
	return true;
}

bool MathLibraryJSS::Vector3::operator!=(const MathLibraryJSS::Vector3& rhs)
{
	float default_Tol = MathHelpers::DEFAULT_TOLERANCE;
	if (abs(x - rhs.x) > default_Tol)
		return true;
	else if (abs(y - rhs.y) > default_Tol)
		return true;
	else if (abs(z - rhs.z) > default_Tol)
		return true;
	return false;
}

float MathLibraryJSS::Vector3::Dot(const MathLibraryJSS::Vector3 inpVec) const
{
	return x * inpVec.x + y * inpVec.y + z * inpVec.z;
}

MathLibraryJSS::Vector3 MathLibraryJSS::Vector3::SourceToDestVec(const MathLibraryJSS::Vector3& destVec) const
{
	return MathLibraryJSS::Vector3(destVec.x - x, destVec.y - y, destVec.z - z);
}

MathLibraryJSS::Vector3 MathLibraryJSS::Vector3::Cross(const MathLibraryJSS::Vector3& other) const
{
	return MathLibraryJSS::Vector3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

float MathLibraryJSS::Vector3::Magnitude() const
{
	return sqrt(x * x + y * y + z * z);
}

MathLibraryJSS::Vector3 MathLibraryJSS::Vector3::normalized() const
{
	float mag = Magnitude();
	return MathLibraryJSS::Vector3(x / mag, y / mag, z / mag);
}

float MathLibraryJSS::Vector3::AngleDegreesBetweenVector(const MathLibraryJSS::Vector3 other) const
{
	return cosf(Dot(other.normalized()) / (Magnitude() * other.Magnitude()));
}

void MathLibraryJSS::Vector3::Normalize()
{
	float mag = Magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
}

MathLibraryJSS::Vector3::~Vector3()
{
}