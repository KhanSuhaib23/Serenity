#include "GameObject2D.h"

namespace serenity { namespace game {

	GameObject2D::GameObject2D(maths::Vector3f position, maths::Vector3f rotation, const GLchar* name) :
		position		(position),
		rotation		(rotation),
		name			(name)
	{

	}

} }