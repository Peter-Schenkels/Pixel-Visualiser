#pragma once
#include <map>
#include <GL/freeglut_std.h>

#include "vector2.hpp"

namespace PV
{
	class PixelVisualiser;
}

namespace PV::Input
{
	class Mouse
	{
	public:
		enum class Button
		{
			LeftButton = GLUT_LEFT_BUTTON,
			MiddleButton = GLUT_MIDDLE_BUTTON,
			RightButton = GLUT_RIGHT_BUTTON,
			None = -1
		};

		enum class State
		{
			Down = GLUT_DOWN,
			Up = GLUT_UP,
			None = -1
		};

	private:
		friend class PV::PixelVisualiser;

		struct Info
		{
			Mouse::Button button = Mouse::Button::None;
			Mouse::State state = Mouse::State::None;
			Vector2<int> position = Vector2(0, 0);
			int windowId = -1;
		};

		static std::map<int, Mouse::Info> currentMouseInfos;

		static void handleMouseEvents(int buttonIn, int stateIn, const int x, const int y);
		static void handlePassiveMouseEvents(const int x, const int y);
	};
}
