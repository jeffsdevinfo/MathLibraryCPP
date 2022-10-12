#include "MathHelpers.h"

float MathLibraryJSS::MathHelpers::DegToRad(float degrees)
{
	return (3.14f / 180.0f) * degrees;
}

float MathLibraryJSS::MathHelpers::RadToDeg(float radians)
{
	return (180.0f / 3.14f) * radians;
}
