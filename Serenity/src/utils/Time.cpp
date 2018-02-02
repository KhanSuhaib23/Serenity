#include "Time.h"

namespace serenity { namespace utils {

	GLfloat Time::deltaTime = 0.0f;

	Time::Time()
	{
		setClock();
	}

	void Time::setClock()
	{
		m_Clock = static_cast<GLfloat> (glfwGetTime());
	}

	GLfloat Time::getElapsedTime()
	{
		return static_cast<GLfloat> (glfwGetTime()) - m_Clock;
	}

} }