#include <map>
#include <GL/freeglut_std.h>

#include "Pixel-Visualiser/headers/keyboard.hpp"
#include "Pixel-Visualiser/headers/pixelVisualiser.hpp"


std::map<PV::Input::Keyboard::Key, PV::Input::Keyboard::KeyInfo> PV::Input::Keyboard::keys;


void PV::Input::Keyboard::handleKeyboardUpEvents(Key key, const int x, const int y)
{
	if(const auto result = keys.find(key); result != keys.end())
	{
		auto& [key, state, windowId, tick] = result->second;

		state = State::Released;
		windowId = glutGetWindow();
		tick = PixelVisualiser::getTick();
	}
}


void PV::Input::Keyboard::handleKeyboardDownEvents(Key key, const int x, const int y)
{
	std::vector<Key> currentPressedKeys;
	keys[key] = KeyInfo{ key, State::Pressed, glutGetWindow(), PixelVisualiser::getTick()};
}


void PV::Input::Keyboard::updateKeyboardEvents()
{
	// Delete released keys
	for(auto& [key, keyInfo] : keys)
	{
		if(keyInfo.state == State::Released)
		{
			keys.erase(key);
		}
	}
}
