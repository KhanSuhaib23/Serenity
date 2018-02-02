#pragma once

#include <GLEW\glew.h>

namespace serenity { namespace render {

	class Color
	{
	public:
		union
		{
			GLuint color;
			struct
			{
				GLubyte a;
				GLubyte b;
				GLubyte g;
				GLubyte r;
			};
		};

	public:
		Color		(	GLuint color);
		Color		(	GLubyte		r, 
						GLubyte		g,
						GLubyte		b,
						GLubyte		a
					);
	};

} }