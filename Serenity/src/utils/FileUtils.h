#pragma once

#include <GLEW\glew.h>

#include <FreeImage\FreeImage.h>	

#include <iostream>
#include <stdio.h>

namespace serenity { namespace utils {

	class FileUtils
	{
	public:
		static GLchar*			loadTextFile			(	const GLchar*		filePath);
		static BYTE*			loadImageFile			(
															const GLchar*		filePath,
															GLuint&				width,
															GLuint&				height
														);

	};

} }