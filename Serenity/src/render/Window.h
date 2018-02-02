#pragma once

#include <iostream>

#include <GLEW\glew.h>
#include <GLFW\glfw3.h>

#include "..\utils\Time.h"

namespace serenity { namespace render {

	class Window
	{
	public:
		static GLFWwindow*					m_Window;

	private:
		GLsizei						m_Width;
		GLsizei						m_Height;
		const GLchar*				m_Title;
		const GLubyte*				m_OpenGLVersion;
		utils::Time					m_Timer;

	public:
		Window					();
		Window					(
									GLsizei				width,
								    GLsizei				height,
								    const GLchar*		title
								);

		~Window();
	
	public:
		void		init				();
		void		update				();
		void		clear				();
		void		disableFrameLimit	();
		bool		windowClosed		();
		bool		versionSupported	(
											GLuint versionMajor,
											GLuint versionMinor
										);

	private:
		static void			windowResizeCallback			(
																GLFWwindow*			window, 
																GLsizei				width, 
																GLsizei				height
															);

	public:
		inline GLsizei				getWidth() { return m_Width; }
		inline GLsizei				getHeight() { return m_Height; }
		inline const GLchar*		getTitle() { return m_Title; }
		inline const GLubyte*		getVersion() { return m_OpenGLVersion; }
		inline const GLuint			getFPS() { return static_cast<GLuint> (1.0f / utils::Time::deltaTime); }
		inline GLFWwindow**			getWindow() { return &m_Window; }

	};

} }