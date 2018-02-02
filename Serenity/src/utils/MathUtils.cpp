#include "MathUtils.h"

namespace serenity { namespace utils {
	
	float const MathUtils::PI = 3.14159265359f;

	float MathUtils::toRadians(const float& degree)
	{
		return (degree * PI / 180.0f);
	}


	float MathUtils::toDegree(const float& radians)
	{
		return (radians * 180.0f / PI);
	}

} }