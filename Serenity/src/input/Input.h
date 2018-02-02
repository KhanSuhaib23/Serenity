#pragma once

#include <GLEW/glew.h>

#include "../render/Window.h"
#include "../maths/Vector.h"

namespace serenity { namespace input {

#define MAX_KEYS 256
#define MAX_BUTTONS 8

	class Input
	{
	private:
		static GLboolean m_KeyHold[MAX_KEYS];
		static GLboolean m_KeyPressed[MAX_KEYS];
		static GLboolean m_KeyReleased[MAX_KEYS];
		static GLboolean buttonHold[MAX_BUTTONS];
		static GLboolean buttonPressed[MAX_BUTTONS];
		static GLboolean buttonReleased[MAX_BUTTONS];
		static serenity::maths::Vector2f m_MousePosition;

	public:
		static void update();

		static bool getKeyHeld(int keyCode);
		static bool getKeyPressed(int keyCode);
		static bool getKeyReleased(int keyCode);
		static bool getMouseButtonHeld(int keyCode);
		static bool getMouseButtonPressed(int keyCode);
		static bool getMouseButtonReleased(int keyCode);

		static float mouseX();
		static float mouseY();
		static serenity::maths::Vector2f mousePosition();

	private:
		static void clear(GLboolean *array, unsigned int length);
		static void updateKeys();
		static void updateButtons();
		static void updateMousePosition();
	};

} }

