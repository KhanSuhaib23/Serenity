#include "Quaternion.h"

namespace serenity { namespace maths {

	Quaternion::Quaternion() :
		Quaternion(0.0f, 0.0f, 0.0f, 0.0f)
	{

	}

	Quaternion::Quaternion(float x, float y, float z, float w) :
		x	(x), 
		y	(y),
		z	(z),
		w	(w)
	{

	}

} }