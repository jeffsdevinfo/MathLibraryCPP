#include "Quaternion.h"

void MathLibraryJSS::Quaternion::operator=(const MathLibraryJSS::Quaternion& rhs)
{
	x = rhs.x; y = rhs.y; z = rhs.z; w = rhs.w;
}

MathLibraryJSS::Quaternion MathLibraryJSS::Quaternion::operator+(const MathLibraryJSS::Quaternion& rhs)
{
	return MathLibraryJSS::Quaternion(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
}

MathLibraryJSS::Quaternion MathLibraryJSS::Quaternion::operator-(const MathLibraryJSS::Quaternion& rhs)
{
	return MathLibraryJSS::Quaternion(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}

MathLibraryJSS::Quaternion MathLibraryJSS::Quaternion::operator*(const MathLibraryJSS::Quaternion& rhs)
{
	return MathLibraryJSS::Quaternion(x * rhs.w + y * rhs.z - z * rhs.y + w * rhs.x,
		-x * rhs.z + y * rhs.w + z * rhs.x + w * rhs.y,
		x * rhs.y - y * rhs.x + z * rhs.w + w * rhs.z,
		-x * rhs.x - y * rhs.y - z * rhs.z + w * rhs.w);
}

MathLibraryJSS::Quaternion MathLibraryJSS::Quaternion::operator*(const float& rhs)
{
	return MathLibraryJSS::Quaternion(x * rhs, y * rhs, z * rhs, w * rhs);
}

MathLibraryJSS::Quaternion MathLibraryJSS::Quaternion::AngleAxis(float angleToRotate, Vector3 axisToRotateOn)
{
	axisToRotateOn.Normalize();
	MathLibraryJSS::Quaternion axis(axisToRotateOn.X() * (float)sinf(angleToRotate / 2.0f),
		axisToRotateOn.Y() * (float)sinf(angleToRotate / 2.0f),
		axisToRotateOn.Z() * (float)sinf(angleToRotate / 2.0f),
		(float)cosf(angleToRotate / 2.0f));
	MathLibraryJSS::Quaternion qInv(-1 * axis.X(), -1 * axis.Y(), -1 * axis.Z(), axis.W());
	MathLibraryJSS::Quaternion returnQuat;
	returnQuat = axis * *this * qInv;
	return returnQuat;
}

MathLibraryJSS::Quaternion MathLibraryJSS::Quaternion::AngleAxisPoint(Vector3 pointToRotate, float angleToRotate, Vector3 axisToRotateOn)
{
	MathLibraryJSS::Quaternion qPointToRotate(pointToRotate);
	return qPointToRotate.AngleAxis(angleToRotate, axisToRotateOn);
}

MathLibraryJSS::Vector3 MathLibraryJSS::Quaternion::AngleAxisPointVec3(Vector3 pointToRotate, float angleToRotate, Vector3 axisToRotateOn)
{
	MathLibraryJSS::Quaternion qPointToRotate(pointToRotate);
	return qPointToRotate.AngleAxis(angleToRotate, axisToRotateOn).Vec3();
}

void MathLibraryJSS::Quaternion::normalize()
{
	float n = sqrtf(x * x + y * y + z * z + w * w);
	x /= n;
	y /= n;
	z /= n;
	w /= n;
}
