#pragma once

namespace serenity { namespace utils {

	class MathUtils
	{
	public:
		static const float PI;

	public:
		static float		toRadians		(	const float&		degree);
		static float		toDegree		(	const float&		radians);
	};

} }