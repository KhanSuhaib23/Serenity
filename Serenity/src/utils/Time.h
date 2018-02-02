#pragma once

#include <GLFW\glfw3.h>

namespace serenity { namespace utils {

	class Time
	{
	public:
		static GLfloat deltaTime;
	private:
		GLfloat m_Clock;

	public:
		Time();

	public:
		void			setClock			();
		GLfloat			getElapsedTime		();
	};

} }