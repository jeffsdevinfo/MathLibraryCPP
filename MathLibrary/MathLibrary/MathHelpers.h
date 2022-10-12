#pragma once
#include "Vector3.h"
#include "Vector4.h"
namespace MathLibraryJSS
{
	//forward declarations - for dependency chain
	class Vector3;
	class Vector4;

	//helper class with a few static utility methods
	class MathHelpers
	{
	public:
		static constexpr float DEFAULT_TOLERANCE{ 0.0001f };

		static float DegToRad(float degrees);	//convert degrees to rads	
		static float RadToDeg(float radians);	//convert radians to degs
		////static Vector3* ConvertFVecToVec3TP(const FVector& inpVec); //convert an FVector to a Vector3
		////static Vector4* ConvertFVecToVec4TP(const FVector& inpVec);	//convert an FVector to a Vector4
		////static void ModifyFVecFromVecTP(FVector* refFVec, Vector4* sourceVecTP); //modify an existing FVector to the components of a Vector4
	};
}

