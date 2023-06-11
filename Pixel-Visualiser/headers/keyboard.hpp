#pragma once
#include <map>


namespace PV
{
	class PixelVisualiser;
}

namespace PV::Input
{
	class Keyboard
	{
	public:
		typedef unsigned char Key;

		enum class State
		{
			Pressed,
			Released,
			None = -1
		};

	private:
		friend class PV::PixelVisualiser;

		struct KeyInfo
		{
			Key key;
			State state = State::None;
			int windowId = -1;
			uint64_t tick;
		};

		static std::map<Key, KeyInfo> keys;

		static void handleKeyboardUpEvents(Key key, const int x, const int y);
		static void handleKeyboardDownEvents(Key key, const int x, const int y);
		static void updateKeyboardEvents();
	};
}
