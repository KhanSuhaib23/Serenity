#include "Input.h"

namespace serenity { namespace input {

	GLboolean Input::m_KeyHold[MAX_KEYS];
	GLboolean Input::m_KeyPressed[MAX_KEYS];
	GLboolean Input::m_KeyReleased[MAX_KEYS];
	
	GLboolean Input::buttonHold[MAX_BUTTONS];
	GLboolean Input::buttonPressed[MAX_BUTTONS];
	GLboolean Input::buttonReleased[MAX_BUTTONS];

	serenity::maths::Vector2f Input::m_MousePosition;

	void Input::update()
	{
		updateKeys();
		updateButtons();
		updateMousePosition();
	}

	/*-----------------------Update Keyboard----------------------------*/

	void Input::updateKeys()
	{
		using namespace render;

		clear(m_KeyReleased, MAX_KEYS);
		for (int i = 0; i < MAX_KEYS; ++i)
		{
			if (!(glfwGetKey(Window::m_Window, i) == GLFW_PRESS) && m_KeyHold[i])
			{
				m_KeyReleased[i] = true;
			}
		}

		clear(m_KeyPressed, MAX_KEYS);
		for (int i = 0; i < MAX_KEYS; ++i)
		{
			if (glfwGetKey(Window::m_Window, i) == GLFW_PRESS && !m_KeyHold[i])
			{
				m_KeyPressed[i] = true;
			}
		}

		clear(m_KeyHold, MAX_KEYS);
		for (int i = 0; i < MAX_KEYS; ++i)
		{
			if (glfwGetKey(Window::m_Window, i) == GLFW_PRESS)
			{
				m_KeyHold[i] = true;
			}
		}

	}

	/*-----------------------Mouse Updates----------------------------*/

	void Input::updateButtons()
	{
		using namespace render;

		clear(buttonReleased, MAX_BUTTONS);
		for (int i = 0; i < MAX_BUTTONS; ++i)
		{
			if (!(glfwGetMouseButton(Window::m_Window, i) == GLFW_PRESS) && buttonHold[i])
			{
				buttonReleased[i] = true;
			}
		}

		clear(buttonPressed, MAX_BUTTONS);
		for (int i = 0; i < MAX_BUTTONS; ++i)
		{
			if (glfwGetMouseButton(Window::m_Window, i) == GLFW_PRESS && !buttonHold[i])
			{
				buttonPressed[i] = true;
			}
		}

		clear(buttonHold, MAX_BUTTONS);
		for (int i = 0; i < MAX_BUTTONS; ++i)
		{
			if (glfwGetMouseButton(Window::m_Window, i) == GLFW_PRESS)
			{
				buttonHold[i] = true;
			}
		}
	}

	void Input::updateMousePosition()
	{
		using namespace render;
		double xpos = 0.0;
		double ypos = 0.0;
		glfwGetCursorPos(Window::m_Window, &xpos, &ypos);
		m_MousePosition.x = static_cast<float> (xpos);
		m_MousePosition.y = static_cast<float> (ypos);

	}

	/*-----------------------Clear----------------------------*/

	void Input::clear(GLboolean*array, unsigned int length)
	{
		memset(array, 0, length);
	}

	/*-----------------------Keyboard----------------------------*/

	bool Input::getKeyHeld(int keyCode)
	{
		return m_KeyHold[keyCode];
	}

	bool Input::getKeyPressed(int keyCode)
	{
		return m_KeyPressed[keyCode];
	}

	bool Input::getKeyReleased(int keyCode)
	{
		return m_KeyReleased[keyCode];
	}

	/*-----------------------Mouse Button----------------------------*/

	bool Input::getMouseButtonHeld(int keyCode)
	{
		return buttonHold[keyCode];
	}

	bool Input::getMouseButtonPressed(int keyCode)
	{
		return buttonPressed[keyCode];
	}

	bool Input::getMouseButtonReleased(int keyCode)
	{
		return buttonReleased[keyCode];
	}

	/*-----------------------Mouse Position----------------------------*/

	float Input::mouseX()
	{
		return m_MousePosition.x;
	}

	float Input::mouseY()
	{
		return m_MousePosition.y;
	}

	serenity::maths::Vector2f Input::mousePosition()
	{
		return m_MousePosition;
	}


} }