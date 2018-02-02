#include "Color.h"

namespace serenity { namespace render {

	Color::Color(GLuint color) :
		color		(color)
	{

	}

	Color::Color(GLubyte r, GLubyte g, GLubyte b, GLubyte a) :
		r			(r),
		g			(g),
		b			(b),
		a			(a)
	{

	}

} }