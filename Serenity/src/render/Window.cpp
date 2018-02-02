#include "Window.h"

namespace serenity { namespace render {

	GLFWwindow* Window::m_Window = nullptr;

	Window::Window()
	{

	}

	Window::Window(GLsizei width, GLsizei height, const GLchar* title) :
		m_Width			(width),
		m_Height		(height),
		m_Title			(title)
	{

	}

	void Window::init()
	{
		if (glfwInit() != GLFW_TRUE)
		{
			std::cout << "Failed To Initialize GLFW" << std::endl;
			system("PAUSE");
			exit(-1);
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Window = glfwCreateWindow(m_Width, 
									m_Height, 
									m_Title, 
									nullptr, 
									nullptr);

		if (m_Window == nullptr)
		{
			std::cout << "Failed To Create Window" << std::endl;
			system("PAUSE");
			glfwTerminate();
			exit(-1);
		}

		glfwMakeContextCurrent(m_Window);

		glfwSetWindowSizeCallback(m_Window, 
								  windowResizeCallback);

		if (glewInit() != GLEW_OK)
		{
			std::cout << "Failed To Initialize GLEW" << std::endl;
			system("PAUSE");
			glfwTerminate();
			exit(-1);
		}

		m_OpenGLVersion = glGetString(GL_VERSION);
	}

	bool Window::versionSupported(GLuint versionMajor, GLuint versionMinor)
	{
		GLuint _versionMajor = m_OpenGLVersion[0] - '0';
		GLuint _versionMinor = m_OpenGLVersion[2] - '0';

		if (_versionMajor < versionMajor)
		{
			return false;
		}
		else if (_versionMajor == versionMajor)
		{
			if (_versionMinor < versionMinor)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return true;
		}
	}

	void Window::update()
	{
		m_Timer.setClock();
		glfwPollEvents();
		glfwGetWindowSize(m_Window, 
						  &m_Width, 
						  &m_Height);

		glfwSwapBuffers(m_Window);

		utils::Time::deltaTime = m_Timer.getElapsedTime();
	}

	void Window::clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	void Window::disableFrameLimit()
	{
		glfwSwapInterval(0);
	}

	bool Window::windowClosed()
	{
		return glfwWindowShouldClose(m_Window) == 1;
	}

	void Window::windowResizeCallback(GLFWwindow* window, GLsizei width, GLsizei height)
	{
		glViewport(0, 
				   0, 
				   width, 
				   height);
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

} }