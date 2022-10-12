// Fill out your copyright notice in the Description page of Project Settings.
#include "Matrix4.h"
#include "MathHelpers.h"

MathLibraryJSS::Matrix4::Matrix4(const MathLibraryJSS::Matrix4& inpMat)
{
	Set(inpMat.mXx, inpMat.mXy, inpMat.mXz, inpMat.mXw,
		inpMat.mYx, inpMat.mYy, inpMat.mYz, inpMat.mYw,
		inpMat.mZx, inpMat.mZy, inpMat.mZz, inpMat.mZw,
		inpMat.mTx, inpMat.mTy, inpMat.mTz, inpMat.mTw);
}

MathLibraryJSS::Matrix4::Matrix4(float inp_mXx, float inp_mXy, float inp_mXz, float inp_mXw,
	float inp_mYx, float inp_mYy, float inp_mYz, float inp_mYw,
	float inp_mZx, float inp_mZy, float inp_mZz, float inp_mZw,
	float inp_mTx, float inp_mTy, float inp_mTz, float inp_mTw)
{
	Set(inp_mXx, inp_mXy, inp_mXz, inp_mXw,
		inp_mYx, inp_mYy, inp_mYz, inp_mYw,
		inp_mZx, inp_mZy, inp_mZz, inp_mZw,
		inp_mTx, inp_mTy, inp_mTz, inp_mTw);
}

void MathLibraryJSS::Matrix4::Set(float inp_mXx, float inp_mXy, float inp_mXz, float inp_mXw,
	float inp_mYx, float inp_mYy, float inp_mYz, float inp_mYw,
	float inp_mZx, float inp_mZy, float inp_mZz, float inp_mZw,
	float inp_mTx, float inp_mTy, float inp_mTz, float inp_mTw)
{
	mXx = inp_mXx; mYx = inp_mYx; mZx = inp_mZx; mTx = inp_mTx;
	mXy = inp_mXy; mYy = inp_mYy; mZy = inp_mZy; mTy = inp_mTy;
	mXz = inp_mXz; mYz = inp_mYz; mZz = inp_mZz; mTz = inp_mTz;
	mXw = inp_mXw; mYw = inp_mYw; mZw = inp_mZw; mTw = inp_mTw;
}

void MathLibraryJSS::Matrix4::Set(const MathLibraryJSS::Matrix4 refMat)
{
	mXx = refMat.mXx; mYx = refMat.mYx; mZx = refMat.mZx; mTx = refMat.mTx;
	mXy = refMat.mXy; mYy = refMat.mYy; mZy = refMat.mZy; mTy = refMat.mTy;
	mXz = refMat.mXz; mYz = refMat.mYz; mZz = refMat.mZz; mTz = refMat.mTz;
	mXw = refMat.mXw; mYw = refMat.mYw; mZw = refMat.mZw; mTw = refMat.mTw;
}

MathLibraryJSS::Matrix4 MathLibraryJSS::Matrix4::operator*(const MathLibraryJSS::Matrix4& rhs) const
{
	return MathLibraryJSS::Matrix4(
		(mXx * rhs.mXx) + (mYx * rhs.mXy) + (mZx * rhs.mXz) + (mTx * rhs.mXw),
		(mXy * rhs.mXx) + (mYy * rhs.mXy) + (mZy * rhs.mXz) + (mTy * rhs.mXw),
		(mXz * rhs.mXx) + (mYz * rhs.mXy) + (mZz * rhs.mXz) + (mTz * rhs.mXw),
		(mXw * rhs.mXx) + (mYw * rhs.mXy) + (mZw * rhs.mXz) + (mTw * rhs.mXw),

		(mXx * rhs.mYx) + (mYx * rhs.mYy) + (mZx * rhs.mYz) + (mTx * rhs.mYw),
		(mXy * rhs.mYx) + (mYy * rhs.mYy) + (mZy * rhs.mYz) + (mTy * rhs.mYw),
		(mXz * rhs.mYx) + (mYz * rhs.mYy) + (mZz * rhs.mYz) + (mTz * rhs.mYw),
		(mXw * rhs.mYx) + (mYw * rhs.mYy) + (mZw * rhs.mYz) + (mTw * rhs.mYw),

		(mXx * rhs.mZx) + (mYx * rhs.mZy) + (mZx * rhs.mZz) + (mTx * rhs.mZw),
		(mXy * rhs.mZx) + (mYy * rhs.mZy) + (mZy * rhs.mZz) + (mTy * rhs.mZw),
		(mXz * rhs.mZx) + (mYz * rhs.mZy) + (mZz * rhs.mZz) + (mTz * rhs.mZw),
		(mXw * rhs.mZx) + (mYw * rhs.mZy) + (mZw * rhs.mZz) + (mTw * rhs.mZw),

		(mXx * rhs.mTx) + (mYx * rhs.mTy) + (mZx * rhs.mTz) + (mTx * rhs.mTw),
		(mXy * rhs.mTx) + (mYy * rhs.mTy) + (mZy * rhs.mTz) + (mTy * rhs.mTw),
		(mXz * rhs.mTx) + (mYz * rhs.mTy) + (mZz * rhs.mTz) + (mTz * rhs.mTw),
		(mXw * rhs.mTx) + (mYw * rhs.mTy) + (mZw * rhs.mTz) + (mTw * rhs.mTw));
}

MathLibraryJSS::Matrix4 MathLibraryJSS::Matrix4::operator*(const float& rhv) const
{
	return MathLibraryJSS::Matrix4();
}

MathLibraryJSS::Vector4 MathLibraryJSS::Matrix4::operator*(const Vector4& rhs) const
{
	return Vector4(
		(mXx * rhs.X()) + (mYx * rhs.Y()) + (mZx * rhs.Z()) + (mTx * rhs.W()),
		(mXy * rhs.X()) + (mYy * rhs.Y()) + (mZy * rhs.Z()) + (mTy * rhs.W()),
		(mXz * rhs.X()) + (mYz * rhs.Y()) + (mZz * rhs.Z()) + (mTz * rhs.W()),
		(mXw * rhs.X()) + (mYw * rhs.Y()) + (mZw * rhs.Z()) + (mTw * rhs.W()));
}

MathLibraryJSS::Matrix4& MathLibraryJSS::Matrix4::operator=(const MathLibraryJSS::Matrix4& rhv)
{
	this->mXx = rhv.mXx; this->mXy = rhv.mXy; this->mXz = rhv.mXz; this->mXw = rhv.mXw;
	this->mYx = rhv.mYx; this->mYy = rhv.mYy; this->mYz = rhv.mYz; this->mYw = rhv.mYw;
	this->mZx = rhv.mZx; this->mZy = rhv.mZy; this->mZz = rhv.mZz; this->mZw = rhv.mZw;
	this->mTx = rhv.mTx; this->mTy = rhv.mTy; this->mTz = rhv.mTz; this->mTw = rhv.mTw;
	return *this;
}

bool MathLibraryJSS::Matrix4::operator==(const MathLibraryJSS::Matrix4& rhs) const
{
	float default_Tol = MathHelpers::DEFAULT_TOLERANCE;
	if (abs(mXx - rhs.mXx) > default_Tol)
		return false;
	if (abs(mXy - rhs.mXy) > default_Tol)
		return false;
	if (abs(mXz - rhs.mXz) > default_Tol)
		return false;
	if (abs(mXw - rhs.mXw) > default_Tol)
		return false;

	if (abs(mYx - rhs.mYx) > default_Tol)
		return false;
	if (abs(mYy - rhs.mYy) > default_Tol)
		return false;
	if (abs(mYz - rhs.mYz) > default_Tol)
		return false;
	if (abs(mYw - rhs.mYw) > default_Tol)
		return false;

	if (abs(mZx - rhs.mZx) > default_Tol)
		return false;
	if (abs(mZy - rhs.mZy) > default_Tol)
		return false;
	if (abs(mZz - rhs.mZz) > default_Tol)
		return false;
	if (abs(mZw - rhs.mZw) > default_Tol)
		return false;

	if (abs(mTx - rhs.mTx) > default_Tol)
		return false;
	if (abs(mTy - rhs.mTy) > default_Tol)
		return false;
	if (abs(mTz - rhs.mTz) > default_Tol)
		return false;
	if (abs(mTw - rhs.mTw) > default_Tol)
		return false;

	return true;
}

bool MathLibraryJSS::Matrix4::operator!=(const MathLibraryJSS::Matrix4& rhs) const
{
	float default_Tol = MathHelpers::DEFAULT_TOLERANCE;
	if (abs(mXx - rhs.mXx) > default_Tol)
		return true;
	if (abs(mXy - rhs.mXy) > default_Tol)
		return true;
	if (abs(mXz - rhs.mXz) > default_Tol)
		return true;
	if (abs(mXw - rhs.mXw) > default_Tol)
		return true;

	if (abs(mYx - rhs.mYx) > default_Tol)
		return true;
	if (abs(mYy - rhs.mYy) > default_Tol)
		return true;
	if (abs(mYz - rhs.mYz) > default_Tol)
		return true;
	if (abs(mYw - rhs.mYw) > default_Tol)
		return true;
	if (abs(mZw - rhs.mZw) > default_Tol)
		return true;

	if (abs(mZx - rhs.mZx) > default_Tol)
		return true;
	if (abs(mZy - rhs.mZy) > default_Tol)
		return true;
	if (abs(mZz - rhs.mZz) > default_Tol)
		return true;
	if (abs(mZw - rhs.mZw) > default_Tol)
		return true;

	if (abs(mTx - rhs.mTx) > default_Tol)
		return true;
	if (abs(mTy - rhs.mTy) > default_Tol)
		return true;
	if (abs(mTz - rhs.mTz) > default_Tol)
		return true;
	if (abs(mTw - rhs.mTw) > default_Tol)
		return true;

	return false;
}

void MathLibraryJSS::Matrix4::SetRotateX(const float& AngleInDegrees)
{
	float rotationRadians = MathHelpers::DegToRad(AngleInDegrees);
	Set(1, 0, 0, 0,                                         //xaxis
		0, cos(rotationRadians), (sin(rotationRadians)), 0, //yaxis
		0, -sin(rotationRadians), cos(rotationRadians), 0,  //zxis
		0, 0, 0, 1);                                        //taxis
}

void MathLibraryJSS::Matrix4::SetRotateY(const float& AngleInDegrees)
{
	float rotationRadians = MathHelpers::DegToRad(AngleInDegrees);
	Set(cos(rotationRadians), 0, (-sin(rotationRadians)), 0,  //xaxis
		0, 1, 0, 0,											  //yaxis
		sin(rotationRadians), 0, cos(rotationRadians), 0,     //zaxis
		0, 0, 0, 1);                                          //taxis
}

void MathLibraryJSS::Matrix4::SetRotateZ(const float& AngleInDegrees)
{
	float rotationRadians = MathHelpers::DegToRad(AngleInDegrees);
	Set(cos(rotationRadians), sin(rotationRadians), 0, 0,      //x axis which is a column
		-sin(rotationRadians), cos(rotationRadians), 0, 0,     //y axis
		0, 0, 1, 0,                                            //z axis
		0, 0, 0, 1);                                           //t axis          
}

void MathLibraryJSS::Matrix4::SetTranslation(const Vector4& transVec)
{
	mTx = transVec.X();
	mTy = transVec.Y();
	mTz = transVec.Z();
	mTw = transVec.W();
}

void MathLibraryJSS::Matrix4::RotateX(const float& AngleInDegrees)
{
	MathLibraryJSS::Matrix4 temp(true);
	temp.SetRotateX(AngleInDegrees);
	Set(*this * temp);
}

void MathLibraryJSS::Matrix4::RotateY(const float& AngleInDegrees)
{
	MathLibraryJSS::Matrix4 temp(true);
	temp.SetRotateY(AngleInDegrees);
	Set(*this * temp);
}

void MathLibraryJSS::Matrix4::RotateZ(const float& AngleInDegrees)
{
	MathLibraryJSS::Matrix4 temp(true);
	temp.SetRotateZ(AngleInDegrees);
	Set(*this * temp);
}

void MathLibraryJSS::Matrix4::Translate(const Vector4& transVec)
{
	mTx += transVec.X();
	mTy += transVec.Y();
	mTz += transVec.Z();
}