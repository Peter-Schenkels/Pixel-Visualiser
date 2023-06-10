#include "Pixel-Visualiser/headers/mouse.hpp"

#include <iostream>
#include <map>

std::map<int, PV::Input::Mouse::Info> PV::Input::Mouse::currentMouseInfos;


void PV::Input::Mouse::handleMouseEvents(int buttonIn, int stateIn, const int x, const int y)
{
	auto& [button, state, position, windowId] = currentMouseInfos[glutGetWindow()];

	button		= static_cast<Button>(buttonIn);
	state		= static_cast<State>(stateIn);
	position	= Vector2(x, y);
	windowId	= glutGetWindow();
}


void PV::Input::Mouse::handlePassiveMouseEvents(const int x, const int y)
{
	auto& [button, state, position, windowId] = currentMouseInfos[glutGetWindow()];

	button		= Button::None;
	state		= State::None;
	position	= Vector2(x, y);
	windowId	= glutGetWindow();
}
